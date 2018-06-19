// Fill out your copyright notice in the Description page of Project Settings.

#include "ABCharacter.h"
#include "components/StaticMeshComponent.h"
#include "MotionControllerComponent.h"
#include "Animation/SkeletalMeshActor.h"
#include "DrawDebugHelpers.h"

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

//VIVE_PawnCharacter >> GripDropOrUseObject
//VIVE_PawnCharacter >> SelectObjectFromHitArray
//VIVE_PawnCharacter >> ShouldGripComponent
//VIVE_PawnCharacter >> GetNearestOverlappingObject
//VIVE_PawnCharacter >> SelectObjectFromHitArray
//VIVE_PawnCharacter >> ShouldGripComponent

void AABCharacter::GripDropOrUseObject(UGripMotionControllerComponent* Hand, USphereComponent* GrabArea, UGripMotionControllerComponent* OtherHand)
{
	UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | %s"), *Hand->GetName());
	if (Hand->HasGrippedObjects())
	{
		EControllerHand HandType;
		Hand->GetHandType(HandType);
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

		// Sweep and Overlap for the above varibales
		if (ObjectFound)
		{
			//Todo, if multiple items -- determine priority.
			FHitResult Hit = OutHits[0];
			Component = Hit.GetComponent();
			Actor = Hit.GetActor();
			BoneName = Hit.BoneName;
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
			if (Grippable && !Grippable->DenyGripping())
			{
				UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | TODO: <Grippable> Component or Actor & !DenyGripping"));
				//TODO implement grippable objects!
				//ServerTryGrab(Hand, ObjectToGrip, Hit);
			}
			else if (Component->IsSimulatingPhysics(BoneName))
			{
				//GripDropOrUseObjectClean >> "PlainOrBoneTransform"
				UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject | <Component> isSimulatingPhysics"));
				FTransform Transform;
				if (BoneName == FName("None"))
				{
					Transform = ObjectTransform;
				}
				else
				{
					GetBoneTransform(Transform, ObjectToGrip, BoneName);
				}

				EControllerHand HandType;
				Hand->GetHandType(HandType);

				Transform = Hand->ConvertToControllerRelativeTransform(Transform);
				ServerTryGrab(HandType, ObjectToGrip, Transform, BoneName);
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

//TryToGrabObject 
void AABCharacter::ServerTryGrab_Implementation(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName)
{
	UE_LOG(LogTemp, Warning, TEXT("ServerTryGrab ObjectToGrip %s"), *ObjectToGrip->GetName())
	UGripMotionControllerComponent* Hand = EHand == EControllerHand::Left ? LeftHand : RightHand;
	UGripMotionControllerComponent* OtherHand = EHand != EControllerHand::Left ? LeftHand : RightHand;

	TArray<UObject*> OtherHandHolding;
	OtherHand->GetGrippedObjects(OtherHandHolding);
	if (OtherHandHolding.Contains(ObjectToGrip)) 
	{
		OtherHand->DropObject(ObjectToGrip, true);
	}
	//TODO: Will be a function arguement in the near future
	bool IsSlotGrip = false;

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
		IsSlotGrip);
}

bool AABCharacter::ServerTryGrab_Validate(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName)
{
	return true;
}

void AABCharacter::ServerTryDropAll_Implementation(EControllerHand EHand)
{
	UGripMotionControllerComponent* Hand = EHand == EControllerHand::Left ? LeftHand : RightHand;

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