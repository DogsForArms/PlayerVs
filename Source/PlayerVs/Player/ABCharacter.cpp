// Fill out your copyright notice in the Description page of Project Settings.

#include "ABCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "MotionControllerComponent.h"
#include "Animation/SkeletalMeshActor.h"
#include "DrawDebugHelpers.h"
#include "VRGlobalSettings.h"
#include "VoiceConfig.h"
#include "Online/SteamHandler.h"
#include "GameFramework/PlayerController.h"
#include "Actors/GunBase.h"
#include "PlayerVs.h"
#include "Net/UnrealNetwork.h"
#include "Online/ABGameMode.h"

//////////////////////////////////////////////////////////////////////////
// Initialization
AABCharacter::AABCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GripTraceLength = 1.f;

	Talker = CreateDefaultSubobject<UVOIPTalker>("Talker");
	WidgetInteractionLeft = CreateDefaultSubobject<UWidgetInteractionComponent>("WidgetInteractionLeft");
	WidgetInteractionLeft->SetupAttachment(LeftMotionController);
	WidgetInteractionRight = CreateDefaultSubobject<UWidgetInteractionComponent>("WidgetInteractionRight");
	WidgetInteractionRight->SetupAttachment(RightMotionController);

	HolsterArea = CreateDefaultSubobject<UStaticMeshComponent>("Holster");
	HolsterArea->SetupAttachment(ParentRelativeAttachment);

	HolsterArea->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	HolsterArea->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	HolsterArea->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	HolsterArea->SetGenerateOverlapEvents(true);
	HolsterArea->OnComponentBeginOverlap.AddDynamic(this, &AABCharacter::OnBeginOverlapHolster);
	HolsterArea->OnComponentEndOverlap.AddDynamic(this, &AABCharacter::OnEndOverlapHolster);

	Body = CreateDefaultSubobject<UStaticMeshComponent>("Body");
	Body->SetupAttachment(ParentRelativeAttachment);
	Body->SetGenerateOverlapEvents(false);
	Body->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	Body->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECR_Block);

	Head = CreateDefaultSubobject<UStaticMeshComponent>("Head");
	Head->SetupAttachment(VRReplicatedCamera);
	Head->SetGenerateOverlapEvents(false);
	Head->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	Head->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECR_Block);

	LeftHandMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeftHandMesh");
	LeftHandMesh->SetGenerateOverlapEvents(false);
	LeftHandMesh->SetupAttachment(LeftMotionController);
	LeftHandMesh->SetCollisionResponseToAllChannels(ECR_Ignore);

	RightHandMesh = CreateDefaultSubobject<UStaticMeshComponent>("RightHandMesh");
	RightHandMesh->SetGenerateOverlapEvents(false);
	RightHandMesh->SetupAttachment(RightMotionController);
	RightHandMesh->SetCollisionResponseToAllChannels(ECR_Ignore);

	LeftHandGrabArea = CreateDefaultSubobject<USphereComponent>("LeftHandGrab");
	LeftHandGrabArea->SetSphereRadius(8.f);
	LeftHandGrabArea->SetupAttachment(LeftMotionController);

	RightHandGrabArea = CreateDefaultSubobject<USphereComponent>("RightHandGrab");
	RightHandGrabArea->SetSphereRadius(8.f);
	RightHandGrabArea->SetupAttachment(RightMotionController);

	VRRootReference->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	VRRootReference->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECR_Ignore);

	PrimaryActorTick.bCanEverTick = true;

	Health = 100.f;
}

void AABCharacter::PreReplication(IRepChangedPropertyTracker & ChangedPropertyTracker)
{
	Super::PreReplication(ChangedPropertyTracker);

	// Only replicate this property for a short duration after it changes so join in progress players don't get spammed with fx when joining late
	DOREPLIFETIME_ACTIVE_OVERRIDE(AABCharacter, LastTakeHitInfo, GetWorld() && GetWorld()->GetTimeSeconds() < LastTakeHitTimeTimeout);
}

void AABCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AABCharacter, Health);
	DOREPLIFETIME_CONDITION(AABCharacter, LastTakeHitInfo, COND_Custom);
}

void AABCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(WaitForPlayerStateHandle, this, &AABCharacter::TrySetupTalker, 0.2f, true);
}

void AABCharacter::OnBeginOverlapHolster(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherComp == LeftHandGrabArea)
	{
		bLeftHandIsInHolster = true;
	}
	else if (OtherComp == RightHandGrabArea)
	{
		bRightHandIsInHolster = true;
	}
}

void AABCharacter::OnEndOverlapHolster(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (OtherComp == LeftHandGrabArea)
	{
		bLeftHandIsInHolster = false;
	}
	else if (OtherComp == RightHandGrabArea)
	{
		bRightHandIsInHolster = false;
	}
}

bool AABCharacter::HandIsInHolster(UGripMotionControllerComponent* Hand)
{
	if (Hand == LeftMotionController)
	{
		return bLeftHandIsInHolster;
	} else
	if (Hand == RightMotionController)
	{
		return bRightHandIsInHolster;
	}
	return false;
}


void AABCharacter::TrySetupTalker()
{
	if (PlayerState)
	{
		GetWorld()->GetTimerManager().ClearTimer(WaitForPlayerStateHandle);
		SetupTalker();
	}
}

void AABCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void AABCharacter::SetupTalker()
{
	FVoiceSettings Settings = Talker->Settings;
	Settings.ComponentToAttachTo = VRReplicatedCamera;
	Talker->Settings = Settings;
	Talker->RegisterWithPlayerState(PlayerState);
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (PlayerController)
	{
		PlayerController->ToggleSpeaking(true);
	}
}

//////////////////////////////////////////////////////////////////////////
// Tick

void AABCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateWidgetInteraction(WidgetInteractionLeft);
	UpdateWidgetInteraction(WidgetInteractionRight);
}

void AABCharacter::UpdateWidgetInteraction(UWidgetInteractionComponent* WidgetInteraction)
{
	if (WidgetInteraction->IsOverFocusableWidget())
	{
		WidgetInteraction->bShowDebug = true;
	}
	else
	{
		WidgetInteraction->bShowDebug = false;
	}
}

//////////////////////////////////////////////////////////////////////////
// Debugging

void AABCharacter::DebugVoice(bool bDropVoice, bool bLoopback)
{
	FVoiceSettings Settings = Talker->Settings;
	Settings.ComponentToAttachTo = bDropVoice ? NULL : VRReplicatedCamera;
	Talker->Settings = Settings;

	auto Command = bLoopback ? TEXT("OSS.VoiceLoopback 1") : TEXT("OSS.VoiceLoopback 0");
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (PlayerController)
	{
		PlayerController->ConsoleCommand(Command, true);
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void AABCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("ForwardRH", this, &AABCharacter::MoveForwardRH);
	PlayerInputComponent->BindAxis("RightRH", this, &AABCharacter::MoveRightRH);
	PlayerInputComponent->BindAxis("ForwardLH", this, &AABCharacter::MoveForwardLH);
	PlayerInputComponent->BindAxis("RightLH", this, &AABCharacter::MoveRightLH);

	PlayerInputComponent->BindAction("GrabLeft", IE_Pressed, this, &AABCharacter::GrabLeft);
	PlayerInputComponent->BindAction("GrabRight", IE_Pressed, this, &AABCharacter::GrabRight);

	PlayerInputComponent->BindAction("UseLeft", IE_Pressed, this, &AABCharacter::UseLeft);
	PlayerInputComponent->BindAction("UseLeft", IE_Released, this, &AABCharacter::StopUseLeft);

	PlayerInputComponent->BindAction("UseRight", IE_Pressed, this, &AABCharacter::UseRight);
	PlayerInputComponent->BindAction("UseRight", IE_Released, this, &AABCharacter::StopUseRight);
}

//////////////////////////////////////////////////////////////////////////
// Input - Grab or Drop

void AABCharacter::GrabLeft()
{
	GripDropOrUseObject(LeftMotionController, LeftHandGrabArea, RightMotionController);
}

void AABCharacter::GrabRight()
{
	GripDropOrUseObject(RightMotionController, RightHandGrabArea, LeftMotionController);
}

bool AABCharacter::GetGrabScanResults(TArray<FGrabScanResult> &OutResults, USphereComponent* GrabArea)
{
	TMap<UPrimitiveComponent*, bool> Used;

	TArray<FHitResult> OutHits;
	FCollisionQueryParams TraceParams;
	TraceParams.bTraceComplex = true;
	TraceParams.AddIgnoredActor(this);

	ECollisionChannel TraceChannel = ECC_WorldDynamic;
	float Radius = GrabArea->GetScaledSphereRadius();
	FVector Start = GrabArea->GetComponentLocation();
	FVector End = GrabArea->GetForwardVector() * GripTraceLength + Start;
	DrawDebugSphere(GetWorld(), End, Radius, 8, FColor::Blue, false, 3, 0, 1.0);
	bool ObjectFound = GetWorld()->SweepMultiByObjectType(OutHits, Start, End, FQuat(), TraceChannel, FCollisionShape::MakeSphere(Radius), TraceParams);
	UE_LOG(LogTemp, Warning, TEXT("SweepMultiByObjectType %d"), ObjectFound)

	for (FHitResult Hit : OutHits)
	{
		FGrabScanResult Result;
		Result.BoneName = Hit.BoneName;
		Result.ImpactPoint = Hit.ImpactPoint;
		Result.Component = Hit.GetComponent();
		Result.Actor = Hit.GetActor();
		Used.Add(Hit.GetComponent(), true);
		OutResults.Add(Result);
	}
	
	TArray<FOverlapResult> OutOverlaps;
	FComponentQueryParams OverlapParams;
	OverlapParams.bTraceComplex = true;
	OverlapParams.AddIgnoredActor(this);
	ObjectFound = GetWorld()->ComponentOverlapMulti(OutOverlaps, GrabArea, GrabArea->GetComponentLocation(), GrabArea->GetComponentRotation(), OverlapParams);

	for (FOverlapResult Overlap : OutOverlaps)
	{
		if (!Used.Contains(Overlap.GetComponent()))
		{
			FGrabScanResult Result;
			Result.ImpactPoint = Overlap.GetComponent()->GetComponentLocation();
			Result.Component = Overlap.GetComponent();
			Result.Actor = Overlap.GetActor();
			OutResults.Add(Result);
		}
	}

	for (FGrabScanResult &Result : OutResults)
	{
		IVRGripInterface* GrippableComponent = Cast<IVRGripInterface>(Result.Component);
		IVRGripInterface* GrippableActor = Cast<IVRGripInterface>(Result.Actor);
		UE_LOG(LogTemp, Warning, TEXT("GripResultScan %s"), *Result.Actor->GetName())

		if (GrippableComponent)
		{
			Result.ObjectToGrip = Result.Component;
			Result.ObjectTransform = Result.Component->GetComponentTransform();
		}
		else
		{
			Result.ObjectToGrip = Result.Actor;
			Result.ObjectTransform = Result.Actor->GetActorTransform();
		}
	}

	bool bHasResults = OutResults.Num() > 0;
	return bHasResults;
}

void AABCharacter::GripDropOrUseObject(UGripMotionControllerComponent* Hand, USphereComponent* GrabArea, UGripMotionControllerComponent* OtherHand)
{
	if (bIsDying)
		return;

	EControllerHand HandType;
	Hand->GetHandType(HandType);

	if (Hand->HasGrippedObjects())
	{
		CallCorrectDropEvent(Hand);
	}
	else
	{
		TArray<FGrabScanResult> ScanResults;
		if (GetGrabScanResults(ScanResults, GrabArea))
		{
			for (FGrabScanResult &ScanResult : ScanResults)
			{
				IVRGripInterface* Grippable = Cast<IVRGripInterface>(ScanResult.ObjectToGrip);

				UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | Found object to grab..."));

				if (Grippable && !Grippable->Execute_DenyGripping(ScanResult.ObjectToGrip))
				{
					bool OutHadSlotInRange;
					FTransform OutSlotTransform;
					Grippable->Execute_ClosestGripSlotInRange(
						ScanResult.ObjectToGrip,
						ScanResult.ImpactPoint,
						false,
						OutHadSlotInRange,
						OutSlotTransform,
						Hand,
						GetPrimarySlotPrefix(ScanResult.ObjectToGrip, Hand));

					FTransform RelativeObjectTransform = ScanResult.ObjectTransform.GetRelativeTransform(OutSlotTransform);
					FTransform GripTransform;
					if (Hand->bOffsetByControllerProfile)
					{
						GripTransform = RelativeObjectTransform;
					}
					else
					{
						GripTransform = UVRGlobalSettings::AdjustTransformByControllerProfile(FName("None"), RelativeObjectTransform, HandType == EControllerHand::Right);
					}

					if (!OutHadSlotInRange)
					{
						GripTransform = GetHandRelativeTransformOfBoneOrObject(Hand, ScanResult.ObjectToGrip, ScanResult.ObjectTransform, ScanResult.BoneName);
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("HAD GRIP SLOT IN RANGE!"));
					}
					CallCorrectGrabEvent(HandType, ScanResult.ObjectToGrip, GripTransform, ScanResult.BoneName, false);
					break;
				}
				else if (ScanResult.Component->IsSimulatingPhysics(ScanResult.BoneName))
				{
					//GripDropOrUseObjectClean >> "PlainOrBoneTransform"
					UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | <Component> isSimulatingPhysics"));
					FTransform Transform = GetHandRelativeTransformOfBoneOrObject(Hand, ScanResult.ObjectToGrip, ScanResult.ObjectTransform, ScanResult.BoneName);
					CallCorrectGrabEvent(HandType, ScanResult.ObjectToGrip, Transform, ScanResult.BoneName, false);
					break;
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | Denied: Object is not moveable"));
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | Denied: Nothing to Grip"));
		}
	}
}

bool AABCharacter::UseWidget(UGripMotionControllerComponent* Hand, bool bClick)
{
	bool Return = false;
	UWidgetInteractionComponent* InteractionComponent = Hand == LeftMotionController ? WidgetInteractionLeft : WidgetInteractionRight;
	if (InteractionComponent->IsOverInteractableWidget())
	{
		if (bClick)
		{
			InteractionComponent->PressPointerKey(EKeys::LeftMouseButton);
		}
		else
		{
			InteractionComponent->ReleasePointerKey(EKeys::LeftMouseButton);
		}
		Return = true;
	}
	return Return;
}

void AABCharacter::CallCorrectGrabEvent(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName, bool bIsSlotGrip)
{
	if (IsLocalGripOrDropEvent(ObjectToGrip)) 
	{
		TryGrab(EHand, ObjectToGrip, Transform, BoneName, bIsSlotGrip);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Server Try Grab:: TODO untested"));
		ServerTryGrab(EHand, ObjectToGrip, Transform, BoneName, bIsSlotGrip);
	}
}

void AABCharacter::TryGrab(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName, bool bIsSlotGrip)
{
	UGripMotionControllerComponent* Hand = GetHandReference(EHand);
	UGripMotionControllerComponent* OtherHand = Hand == LeftMotionController ? RightMotionController : LeftMotionController;

	TArray<UObject*> OtherHandHolding;
	OtherHand->GetGrippedObjects(OtherHandHolding);
	if (OtherHandHolding.Contains(ObjectToGrip))
	{
		OtherHand->DropObject(ObjectToGrip, true);
	}

	UE_LOG(LogTemp, Warning, TEXT("TestHolster grip %s"), *ObjectToGrip->GetName())

	bool bGripOccured = Hand->GripObjectByInterface(
		ObjectToGrip,
		Transform,
		true,
		BoneName,
		bIsSlotGrip
	);

	if (!bGripOccured)
	{
		//TODO logic for switching hands.
		bGripOccured = Hand->GripObject(
			ObjectToGrip,
			Transform,
			true, //Transform is relative
			FName("None"),
			BoneName,
			EGripCollisionType::InteractiveCollisionWithPhysics,
			EGripLateUpdateSettings::NotWhenCollidingOrDoubleGripping,
			EGripMovementReplicationSettings::ForceClientSideMovement,
			1500.f, //Stiffness
			200.f,  //Damping
			bIsSlotGrip);
	}
}

void AABCharacter::ServerTryGrab_Implementation(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName, bool bIsSlotGrip)
{
	TryGrab(EHand, ObjectToGrip, Transform, BoneName, bIsSlotGrip);
}

bool AABCharacter::ServerTryGrab_Validate(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName, bool bIsSlotGrip)
{
	return true;
}

void AABCharacter::CallCorrectDropEvent(UGripMotionControllerComponent* Hand)
{
	if (!Hand->HasGrippedObjects()) { return; }
	EControllerHand EHand;
	Hand->GetHandType(EHand);

	TArray<UObject*> GrippedObjects;
	Hand->GetGrippedObjects(GrippedObjects);

	if (IsLocalGripOrDropEvent(GrippedObjects[0]))
	{
		DropAll(EHand);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Server Drop All:: TODO untested"));
		ServerDropAll(EHand);
	}
}

void AABCharacter::DropAll(EControllerHand EHand)
{
	UGripMotionControllerComponent* Hand = GetHandReference(EHand);

	TArray<AActor*> GrippedActors;
	Hand->GetGrippedActors(GrippedActors);
	for (AActor *GrippedActor : GrippedActors)
	{
		bool bInventory = HandIsInHolster(Hand);//CanPutInInventory(GrippedActor);
		UE_LOG(LogTemp, Warning, TEXT("PutInInventory %d %s"), bInventory, *GrippedActor->GetName())

		Hand->DropObject(GrippedActor, true);
		if (bInventory)
		{
			PutInInventory(GrippedActor);
			ServerPutInInventory(GrippedActor, GrippedActor->GetActorTransform());
		}
	}
}

void AABCharacter::ServerPutInInventory_Implementation(AActor* GrippedActor, FTransform_NetQuantize transform)
{
	GrippedActor->SetActorTransform(transform);
	PutInInventory(GrippedActor);
}

bool AABCharacter::ServerPutInInventory_Validate(AActor* Actor, FTransform_NetQuantize transform)
{
	return true;
}

void AABCharacter::PutInInventory(AActor* Actor)
{
	Actor->DisableComponentsSimulatePhysics();
	Actor->AttachToComponent(HolsterArea, FAttachmentTransformRules::KeepWorldTransform);
}

bool AABCharacter::CanPutInInventory(AActor* Actor)
{
	TSet<AActor*> Overlaps;
	HolsterArea->GetOverlappingActors(Overlaps, AGunBase::StaticClass());
	UE_LOG(LogTemp, Warning, TEXT("TestHolster overlapping %d"), Overlaps.Num())
	for (AActor* Overlap : Overlaps)
	{
		UE_LOG(LogTemp, Warning, TEXT("TestHolster overlapping %s"), *Overlap->GetName())
	}

	if (Actor && Overlaps.Contains(Actor))
	{
		return true;
	}
	
	return false;
}

void AABCharacter::ServerDropAll_Implementation(EControllerHand EHand)
{
	DropAll(EHand);
}

bool AABCharacter::ServerDropAll_Validate(EControllerHand EHand)
{
	return true;
}

//////////////////////////////////////////////////////////////////////////
// Input - Grab or Use

void AABCharacter::UseLeft()
{
	ClientUse(LeftMotionController, true);
}

void AABCharacter::UseRight()
{
	ClientUse(RightMotionController, true);
}

void AABCharacter::StopUseLeft()
{
	ClientUse(LeftMotionController, false);
}

void AABCharacter::StopUseRight()
{
	ClientUse(RightMotionController, false);
}

void AABCharacter::ClientUse(UGripMotionControllerComponent* Hand, bool bPressed)
{
	if (UseWidget(Hand, bPressed) || !bPressed) return; 

	TArray<UObject*> GrippedObjects;
	Hand->GetGrippedObjects(GrippedObjects);
	for (UObject* GrippedObject : GrippedObjects)
	{
		IVRGripInterface* Grip = Cast<IVRGripInterface>(GrippedObject);
		if (Grip)
		{
			Grip->Execute_OnUsed(GrippedObject);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// Input - DPad Movement

void AABCharacter::MoveRightRH(float Value)
{
	float Forward = GetInputAxisValue(FName("ForwardRH"));
	float Right = GetInputAxisValue(FName("RightRH"));
	AddDpadMovementInput(FVector2D(Right, Forward), RightMotionController);
}

void AABCharacter::MoveRightLH(float Value)
{
	float Forward = GetInputAxisValue(FName("ForwardLH"));
	float Right = GetInputAxisValue(FName("RightLH"));
	AddDpadMovementInput(FVector2D(Right, Forward), LeftMotionController);
}

void AABCharacter::MoveForwardRH(float Value)
{
	MoveRightRH(0);
}

void AABCharacter::MoveForwardLH(float Value)
{
	MoveRightLH(0);
}

void AABCharacter::AddDpadMovementInput(FVector2D DPadDirection, UGripMotionControllerComponent* Hand)
{
	bool HMDEnabled = UVRExpansionFunctionLibrary::GetIsHMDConnected() && UVRExpansionFunctionLibrary::IsInVREditorPreviewOrGame();

	if (!HMDEnabled) {
		return;
	}
	FVector Up = FVector(0, 0, 1.f);
	FVector Forward = FVector::VectorPlaneProject(Hand->GetForwardVector(), Up).GetSafeNormal();
	FVector Right = FVector::VectorPlaneProject(Hand->GetRightVector(), Up).GetSafeNormal();
	FVector Direction = (Forward * DPadDirection.Y + Right * DPadDirection.X);

	GetMovementComponent()->AddInputVector(Direction, false);
}

//////////////////////////////////////////////////////////////////////////
// Private helper methods

FName AABCharacter::GetPrimarySlotPrefix(UObject* ObjectToGrip, UGripMotionControllerComponent* Hand)
{
	return FName("None");
}

FTransform AABCharacter::GetHandRelativeTransformOfBoneOrObject(UGripMotionControllerComponent* Hand, UObject* ObjectToGrip, FTransform ObjectTransform, FName BoneName)
{
	FTransform Transform;
	if (BoneName == FName("None"))
	{
		Transform = ObjectTransform;
	}
	else
	{
		GetBoneTransform(Transform, ObjectToGrip, BoneName);
	}

	Transform = Hand->ConvertToControllerRelativeTransform(Transform);
	return Transform;
}

bool AABCharacter::GetBoneTransform(FTransform& BoneTransform, UObject* ComponentOrActor, FName BoneName)
{
	USceneComponent* Component = Cast<USceneComponent>(ComponentOrActor);
	if (Component)
	{
		BoneTransform = Component->GetSocketTransform(BoneName, RTS_World);
	}

	ASkeletalMeshActor* SkeletalMeshActor = Cast<ASkeletalMeshActor>(ComponentOrActor);
	if (SkeletalMeshActor)
	{
		return GetBoneTransform(BoneTransform, SkeletalMeshActor->GetSkeletalMeshComponent(), BoneName);
	}

	return false;
}

UGripMotionControllerComponent* AABCharacter::GetHandReference(EControllerHand EHand)
{
	switch (EHand) {
	case EControllerHand::Left:
		return LeftMotionController;
	case EControllerHand::Right:
		return RightMotionController;
	default:
		return NULL;
	}
}

bool AABCharacter::IsLocalGripOrDropEvent(UObject* ObjectToGrip)
{
	EGripMovementReplicationSettings GripRepType = EGripMovementReplicationSettings::ForceClientSideMovement;
	IVRGripInterface* GrippableComponent = Cast<IVRGripInterface>(ObjectToGrip);
	if (GrippableComponent)
	{
		GripRepType = GrippableComponent->Execute_GripMovementReplicationType(ObjectToGrip);
	}

	return 
		GripRepType == EGripMovementReplicationSettings::ClientSide_Authoritive ||
		GripRepType == EGripMovementReplicationSettings::ClientSide_Authoritive_NoRep;
}

//////////////////////////////////////////////////////////////////////////
// Health Methods


/** Take damage, handle death */
float AABCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Health -= Damage;

	// Modify based on game rules.
	//AShooterGameMode* const Game = GetWorld()->GetAuthGameMode<AABGameMode>();
	//Damage = Game ? Game->ModifyDamage(Damage, this, DamageEvent, EventInstigator, DamageCauser) : 0.f;

	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (Health <= 0)
	{
		Die(ActualDamage, DamageEvent, EventInstigator, DamageCauser);
	}
	else
	{
		PlayHit(ActualDamage, DamageEvent, EventInstigator ? EventInstigator->GetPawn() : NULL, DamageCauser);
	}

	return Damage;
}

bool AABCharacter::Die(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser)
{
	if (!CanDie(KillingDamage, DamageEvent, Killer, DamageCauser))
	{
		return false;
	}

	Health = FMath::Min(0.0f, Health);

	// if this is an environmental death then refer to the previous killer so that they receive credit (knocked into lava pits, etc)
	UDamageType const* const DamageType = DamageEvent.DamageTypeClass ? DamageEvent.DamageTypeClass->GetDefaultObject<UDamageType>() : GetDefault<UDamageType>();
	Killer = GetDamageInstigator(Killer, *DamageType);

	// TODO tell game mode about kill
	AController* const KilledPlayer = (Controller != NULL) ? Controller : Cast<AController>(GetOwner());
	GetWorld()->GetAuthGameMode<AABGameMode>()->Killed(Killer, KilledPlayer, this, DamageType);

//	NetUpdateFrequency = GetDefault<AABCharacter>()->NetUpdateFrequency;
	GetCharacterMovement()->ForceReplicationUpdate();

	OnDeath(KillingDamage, DamageEvent, Killer ? Killer->GetPawn() : NULL, DamageCauser);
	return true;
}

bool AABCharacter::CanDie(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser) const
{
	if (bIsDying
		|| Role != ROLE_Authority)
	{
		return false;
	}
	return true;
}

void AABCharacter::OnRep_Health()
{
	UE_LOG(LogTemp, Warning, TEXT("Health is %f"), Health)
}

void AABCharacter::KilledBy(APawn* EventInstigator)
{
	if (Role == ROLE_Authority && !bIsDying)
	{
		AController* Killer = NULL;
		if (EventInstigator != NULL)
		{
			Killer = EventInstigator->Controller;
			LastHitBy = NULL;
		}

		Die(Health, FDamageEvent(UDamageType::StaticClass()), Killer, NULL);
	}
}

void AABCharacter::PlayHit(float DamageTaken, struct FDamageEvent const& DamageEvent, class APawn* PawnInstigator, class AActor* DamageCauser)
{
	//TODOS
}

void AABCharacter::OnDeath(float KillingDamage, struct FDamageEvent const& DamageEvent, class APawn* PawnInstigator, class AActor* DamageCauser)
{
	if (bIsDying)
	{
		return;
	}

	bReplicateMovement = false;
	bTearOff = true;
	bIsDying = true;

	if (Role == ROLE_Authority)
	{
		ReplicateHit(KillingDamage, DamageEvent, PawnInstigator, DamageCauser, true);

		DropAll(EControllerHand::Left);
		DropAll(EControllerHand::Right);
	}
	//TODOS
	Body->SetSimulatePhysics(true);
	Head->SetSimulatePhysics(true);

	LeftHandMesh->SetSimulatePhysics(true);
	RightHandMesh->SetSimulatePhysics(true);

	//DetachFromControllerPendingDestroy();
}

void AABCharacter::OnRep_LastTakeHitInfo()
{
	if (LastTakeHitInfo.bKilled)
	{
		OnDeath(LastTakeHitInfo.ActualDamage, LastTakeHitInfo.GetDamageEvent(), LastTakeHitInfo.PawnInstigator.Get(), LastTakeHitInfo.DamageCauser.Get());
	}
	else
	{
		PlayHit(LastTakeHitInfo.ActualDamage, LastTakeHitInfo.GetDamageEvent(), LastTakeHitInfo.PawnInstigator.Get(), LastTakeHitInfo.DamageCauser.Get());
	}
}

void AABCharacter::ReplicateHit(float Damage, struct FDamageEvent const& DamageEvent, class APawn* PawnInstigator, class AActor* DamageCauser, bool bKilled)
{
	const float TimeoutTime = GetWorld()->GetTimeSeconds() + 0.5f;

	FDamageEvent const& LastDamageEvent = LastTakeHitInfo.GetDamageEvent();
	if ((PawnInstigator == LastTakeHitInfo.PawnInstigator.Get()) && (LastDamageEvent.DamageTypeClass == LastTakeHitInfo.DamageTypeClass) && (LastTakeHitTimeTimeout == TimeoutTime))
	{
		// same frame damage
		if (bKilled && LastTakeHitInfo.bKilled)
		{
			// Redundant death take hit, just ignore it
			return;
		}

		// otherwise, accumulate damage done this frame
		Damage += LastTakeHitInfo.ActualDamage;
	}

	LastTakeHitInfo.ActualDamage = Damage;
	LastTakeHitInfo.PawnInstigator = Cast<AABCharacter>(PawnInstigator);
	LastTakeHitInfo.DamageCauser = DamageCauser;
	LastTakeHitInfo.SetDamageEvent(DamageEvent);
	LastTakeHitInfo.bKilled = bKilled;
	LastTakeHitInfo.EnsureReplication();

	LastTakeHitTimeTimeout = TimeoutTime;
}

//FTakeHitInfo
FTakeHitInfo::FTakeHitInfo()
	: ActualDamage(0)
	, DamageTypeClass(NULL)
	, PawnInstigator(NULL)
	, DamageCauser(NULL)
	, DamageEventClassID(0)
	, bKilled(false)
	, EnsureReplicationByte(0)
{}

FDamageEvent& FTakeHitInfo::GetDamageEvent()
{
	switch (DamageEventClassID)
	{
	case FPointDamageEvent::ClassID:
		if (PointDamageEvent.DamageTypeClass == NULL)
		{
			PointDamageEvent.DamageTypeClass = DamageTypeClass ? DamageTypeClass : UDamageType::StaticClass();
		}
		return PointDamageEvent;

	case FRadialDamageEvent::ClassID:
		if (RadialDamageEvent.DamageTypeClass == NULL)
		{
			RadialDamageEvent.DamageTypeClass = DamageTypeClass ? DamageTypeClass : UDamageType::StaticClass();
		}
		return RadialDamageEvent;

	default:
		if (GeneralDamageEvent.DamageTypeClass == NULL)
		{
			GeneralDamageEvent.DamageTypeClass = DamageTypeClass ? DamageTypeClass : UDamageType::StaticClass();
		}
		return GeneralDamageEvent;
	}
}

void FTakeHitInfo::SetDamageEvent(const FDamageEvent& DamageEvent)
{
	DamageEventClassID = DamageEvent.GetTypeID();
	switch (DamageEventClassID)
	{
	case FPointDamageEvent::ClassID:
		PointDamageEvent = *((FPointDamageEvent const*)(&DamageEvent));
		break;
	case FRadialDamageEvent::ClassID:
		RadialDamageEvent = *((FRadialDamageEvent const*)(&DamageEvent));
		break;
	default:
		GeneralDamageEvent = DamageEvent;
	}

	DamageTypeClass = DamageEvent.DamageTypeClass;
}

void FTakeHitInfo::EnsureReplication()
{
	EnsureReplicationByte++;
}