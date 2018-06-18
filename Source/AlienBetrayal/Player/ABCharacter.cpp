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
	UE_LOG(LogTemp, Warning, TEXT("GrabLeft"))
	GripDropOrUseObject(LeftHand, LeftHandGrabArea, RightHand);
}

void AABCharacter::GrabRight()
{
	UE_LOG(LogTemp, Warning, TEXT("GrabRight"))
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
	UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject"));
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
//		DrawDebugLine(GetWorld(), Start, End, FColor::Blue, false, 10, 0, 5);
		DrawDebugSphere(GetWorld(), End, Radius, 4, FColor::Blue, false, 10, 0, 3);
		bool HitFound = GetWorld()->SweepMultiByObjectType(OutHits, Start, End, FQuat(), TraceChannel, FCollisionShape::MakeSphere(Radius), TraceParams);
		if (HitFound)
		{
			//Todo, if multiple items -- determine priority.
			FHitResult Hit = OutHits[0];
			IVRGripInterface* GrippableComponent = Cast<IVRGripInterface>(Hit.Component);
			IVRGripInterface* GrippableActor = Cast<IVRGripInterface>(Hit.Actor);
			FTransform ObjectTransform;
			
			IVRGripInterface* Grippable;
			UObject* ObjectToGrip;
			if (GrippableComponent) 
			{
				Grippable = GrippableComponent;
				ObjectToGrip = Hit.Component.Get();
				ObjectTransform = Hit.Component->GetComponentTransform();
			}
			else
			{
				Grippable = GrippableActor;
				ObjectToGrip = Hit.Actor.Get();
				ObjectTransform = Hit.Actor->GetActorTransform();
			}


			UE_LOG(LogTemp, Warning, TEXT("GripDropOrUseObject: Found object to grab..."));
			if (Grippable && !Grippable->DenyGripping())
			{
				UE_LOG(LogTemp, Warning, TEXT("ServerTyGrab: Hit.Component Grippable & !DenyGripping"));
				//TODO implement grippable objects!
				//ServerTryGrab(Hand, ObjectToGrip, Hit);
			}
			else if (Hit.Component->IsSimulatingPhysics(Hit.BoneName))
			{
				//GripDropOrUseObjectClean >> "PlainOrBoneTransform"
				UE_LOG(LogTemp, Warning, TEXT("ServerTyGrab: Hit.Component isSimulatingPhysics"));
				FTransform Transform;
				if (Hit.BoneName == FName("None"))
				{
					Transform = ObjectTransform;
				} 
				else
				{
					GetBoneTransform(Transform, ObjectToGrip, Hit.BoneName);
				}

				EControllerHand HandType;
				Hand->GetHandType(HandType);

				Transform = Hand->ConvertToControllerRelativeTransform(Transform);
				ServerTryGrab(HandType, ObjectToGrip, Transform, Hit.BoneName);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("ServerTryGrab: DENIED"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Nothing to grab"));
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

void AABCharacter::MoveForwardRH(float Value)
{
	AddDpadMovementInput(FVector2D(0, Value), RightHand);
}

void AABCharacter::MoveRightRH(float Value)
{
	AddDpadMovementInput(FVector2D(Value, 0), RightHand);
}
void AABCharacter::MoveForwardLH(float Value)
{
	AddDpadMovementInput(FVector2D(0, Value), LeftHand);
}

void AABCharacter::MoveRightLH(float Value)
{
	AddDpadMovementInput(FVector2D(Value, 0), LeftHand);
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
	FVector Direction = (Forward * DPadDirection.Y + Right * DPadDirection.X).GetSafeNormal();

	GetMovementComponent()->AddInputVector(Direction, false);
}