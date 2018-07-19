// Fill out your copyright notice in the Description page of Project Settings.

#include "ABCharacter.h"
#include "components/StaticMeshComponent.h"
#include "MotionControllerComponent.h"
#include "Animation/SkeletalMeshActor.h"
#include "DrawDebugHelpers.h"
#include "VRGlobalSettings.h"
#include "VoiceConfig.h"
#include "Online/SteamHandler.h"
#include "GameFramework/PlayerController.h"
#include "Components/WidgetInteractionComponent.h"

//////////////////////////////////////////////////////////////////////////
// Initialization

AABCharacter::AABCharacter()
{
	GripTraceLength = 1.f;
	Talker = CreateDefaultSubobject<UVOIPTalker>("Talker");
	WidgetInteractionLeft = CreateDefaultSubobject<UWidgetInteractionComponent>("WidgetInteractionLeft");
	WidgetInteractionLeft->SetupAttachment(LeftMotionController);
	WidgetInteractionRight = CreateDefaultSubobject<UWidgetInteractionComponent>("WidgetInteractionRight");
	WidgetInteractionRight->SetupAttachment(RightMotionController);

	PrimaryActorTick.bCanEverTick = true;
}

void AABCharacter::InitializeHands(USphereComponent* LeftGrab, USphereComponent* RightGrab)
{
	LeftHandGrabArea = LeftGrab;
	RightHandGrabArea = RightGrab;
}

void AABCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	SetupTalker();
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
	SetupTalker(); //make sure talker was setup
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
	UE_LOG(LogTemp, Warning, TEXT("ComponentOverlapMulti %d"), ObjectFound)

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
	UE_LOG(LogTemp, Warning, TEXT("bHasResults %d"), bHasResults)
	return bHasResults;
}

void AABCharacter::GripDropOrUseObject(UGripMotionControllerComponent* Hand, USphereComponent* GrabArea, UGripMotionControllerComponent* OtherHand)
{
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
	UE_LOG(LogTemp, Warning, TEXT("UseWidget -> %d"), Return)
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
	UE_LOG(LogTemp, Warning, TEXT("ServerTryGrab ObjectToGrip: %s bIsSlotGrip: %d"), *ObjectToGrip->GetName(), bIsSlotGrip)
	UGripMotionControllerComponent* Hand = GetHandReference(EHand);
	UGripMotionControllerComponent* OtherHand = Hand == LeftMotionController ? RightMotionController : LeftMotionController;

	TArray<UObject*> OtherHandHolding;
	OtherHand->GetGrippedObjects(OtherHandHolding);
	if (OtherHandHolding.Contains(ObjectToGrip))
	{
		OtherHand->DropObject(ObjectToGrip, true);
	}

	bool bInterfaceGrab = Hand->GripObjectByInterface(
		ObjectToGrip,
		Transform,
		true,
		BoneName,
		bIsSlotGrip
	);
	UE_LOG(LogTemp, Warning, TEXT("Object is interface grab %d"), bInterfaceGrab)
	if (!bInterfaceGrab)
	{
		//Bla de bla, TODO logic for switching hands.
		Hand->GripObject(
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
		TryDropAll(EHand);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Server Drop All:: TODO untested"));
		ServerTryDropAll(EHand);
	}
}

void AABCharacter::TryDropAll(EControllerHand EHand)
{
	UGripMotionControllerComponent* Hand = GetHandReference(EHand);

	TArray<UObject*> GrippedObjects;
	Hand->GetGrippedObjects(GrippedObjects);
	for (UObject *GrippedObject : GrippedObjects)
	{
		Hand->DropObject(GrippedObject, true);
	}
}

void AABCharacter::ServerTryDropAll_Implementation(EControllerHand EHand)
{
	TryDropAll(EHand);
}

bool AABCharacter::ServerTryDropAll_Validate(EControllerHand EHand)
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
	EGripMovementReplicationSettings GripRepType = EGripMovementReplicationSettings::KeepOriginalMovement;
	IVRGripInterface* GrippableComponent = Cast<IVRGripInterface>(ObjectToGrip);
	if (GrippableComponent)
	{
		GripRepType = GrippableComponent->Execute_GripMovementReplicationType(ObjectToGrip);
	}

	return 
		GripRepType == EGripMovementReplicationSettings::ClientSide_Authoritive ||
		GripRepType == EGripMovementReplicationSettings::ClientSide_Authoritive_NoRep;
}