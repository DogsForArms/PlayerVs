// Fill out your copyright notice in the Description page of Project Settings.

#include "ABCharacter.h"
#include "components/StaticMeshComponent.h"
#include "MotionControllerComponent.h"
#include "Animation/SkeletalMeshActor.h"
#include "DrawDebugHelpers.h"
#include "VRGlobalSettings.h"

AABCharacter::AABCharacter()
{
	GripTraceLength = 1.f;
}

void AABCharacter::InitializeHands(UGripMotionControllerComponent* Left, UGripMotionControllerComponent* Right, USphereComponent* LeftGrab, USphereComponent* RightGrab)
{
	LeftHand = Left;
	RightHand = Right;
	LeftHandGrabArea = LeftGrab;
	RightHandGrabArea = RightGrab;
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
}
void AABCharacter::GrabLeft()
{
	GripDropOrUseObject(LeftHand, LeftHandGrabArea, RightHand);
}

void AABCharacter::GrabRight()
{
	GripDropOrUseObject(RightHand, RightHandGrabArea, LeftHand);
}

void AABCharacter::GripDropOrUseObject(UGripMotionControllerComponent* Hand, USphereComponent* GrabArea, UGripMotionControllerComponent* OtherHand)
{
	EControllerHand HandType;
	Hand->GetHandType(HandType);

	UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | %s"), *Hand->GetName());
	if (Hand->HasGrippedObjects())
	{
		ServerTryDropAll(HandType);
	}
	else
	{
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
		UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | SweepMultiByObjectType %d"), ObjectFound)
		
		//Variables to be initialized by Sweep and Overlap
		AActor* Actor = NULL;
		UPrimitiveComponent* Component = NULL;
		FName BoneName = FName("None");
		FVector ImpactPoint;

		// Sweep and Overlap for the above varibales
		if (ObjectFound)
		{
			//Todo, if multiple items -- determine priority.
			FHitResult Hit = OutHits[0];
			Component = Hit.GetComponent();
			Actor = Hit.GetActor();
			BoneName = Hit.BoneName;
			ImpactPoint = Hit.ImpactPoint;
		}
		else
		{//Try ComponentOverlapMulti
			TArray<FOverlapResult> OutOverlaps;
			FComponentQueryParams OverlapParams;
			OverlapParams.bTraceComplex = true;
			OverlapParams.AddIgnoredActor(this);
			ObjectFound = GetWorld()->ComponentOverlapMulti(OutOverlaps, GrabArea, GrabArea->GetComponentLocation(), GrabArea->GetComponentRotation(), OverlapParams);
			if (ObjectFound)
			{
				FOverlapResult Overlap = OutOverlaps[0];
				Component = Overlap.Component.Get();
				Actor = Overlap.Actor.Get();
				ImpactPoint = Component->GetComponentLocation();
			}
			
			UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | ComponentOverlapMulti %d"), ObjectFound)
		}

		if (ObjectFound)
		{
			IVRGripInterface* GrippableComponent = Cast<IVRGripInterface>(Component);
			IVRGripInterface* GrippableActor = Cast<IVRGripInterface>(Actor);
			IVRGripInterface* Grippable = NULL;
			UObject* ObjectToGrip = NULL;
			FTransform ObjectTransform;

			if (GrippableComponent)
			{
				Grippable = GrippableComponent;
				ObjectToGrip = Component;
				ObjectTransform = Component->GetComponentTransform();
			}
			else
			{
				Grippable = GrippableActor;
				ObjectToGrip = Actor;
				ObjectTransform = Actor->GetActorTransform();
			}

			UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | Found object to grab..."));
			
			if (Grippable && !Grippable->Execute_DenyGripping(ObjectToGrip))
			{
				bool OutHadSlotInRange;
				FTransform OutSlotTransform;
				Grippable->Execute_ClosestGripSlotInRange(ObjectToGrip, ImpactPoint, false, OutHadSlotInRange, OutSlotTransform, Hand, GetPrimarySlotPrefix(ObjectToGrip, Hand));

				FTransform RelativeObjectTransform = ObjectTransform.GetRelativeTransform(OutSlotTransform);
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
					GripTransform = GetHandRelativeTransformOfBoneOrObject(Hand, ObjectToGrip, ObjectTransform, BoneName);
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("HAD GRIP SLOT IN RANGE!"));
				}
				ServerTryGrab(HandType, ObjectToGrip, GripTransform, BoneName, false);
			}
			else if (Component->IsSimulatingPhysics(BoneName))
			{
				//GripDropOrUseObjectClean >> "PlainOrBoneTransform"
				UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | <Component> isSimulatingPhysics"));
				FTransform Transform = GetHandRelativeTransformOfBoneOrObject(Hand, ObjectToGrip, ObjectTransform, BoneName);
				ServerTryGrab(HandType, ObjectToGrip, Transform, BoneName, false);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | Denied: Object is not moveable"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | Denied: Nothing to Grip"));
		}
	}
}

void AABCharacter::ServerTryGrab_Implementation(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName, bool bIsSlotGrip)
{
	UE_LOG(LogTemp, Warning, TEXT("ServerTryGrab ObjectToGrip: %s bIsSlotGrip: %d"), *ObjectToGrip->GetName(), bIsSlotGrip)
	UGripMotionControllerComponent* Hand = GetHandReference(EHand);
	UGripMotionControllerComponent* OtherHand = Hand == LeftHand ? RightHand : LeftHand;

	TArray<UObject*> OtherHandHolding;
	OtherHand->GetGrippedObjects(OtherHandHolding);
	if (OtherHandHolding.Contains(ObjectToGrip)) 
	{
		OtherHand->DropObject(ObjectToGrip, true);
	}

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

bool AABCharacter::ServerTryGrab_Validate(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName, bool bIsSlotGrip)
{
	return true;
}

void AABCharacter::ServerTryDropAll_Implementation(EControllerHand EHand)
{
	UGripMotionControllerComponent* Hand = GetHandReference(EHand);

	TArray<UObject*> GrippedObjects;
	Hand->GetGrippedObjects(GrippedObjects);
	for (UObject *GrippedObject : GrippedObjects)
	{
		Hand->DropObject(GrippedObject, true);
	}
}

bool AABCharacter::ServerTryDropAll_Validate(EControllerHand EHand)
{
	return true;
}

void AABCharacter::MoveRightRH(float Value)
{
	float Forward = GetInputAxisValue(FName("ForwardRH"));
	float Right = GetInputAxisValue(FName("RightRH"));
	AddDpadMovementInput(FVector2D(Right, Forward), RightHand);
}

void AABCharacter::MoveRightLH(float Value)
{
	float Forward = GetInputAxisValue(FName("ForwardLH"));
	float Right = GetInputAxisValue(FName("RightLH"));
	AddDpadMovementInput(FVector2D(Right, Forward), LeftHand);
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
		return LeftHand;
	case EControllerHand::Right:
		return RightHand;
	default:
		return NULL;
	}
}