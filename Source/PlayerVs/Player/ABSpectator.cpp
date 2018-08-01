// Fill out your copyright notice in the Description page of Project Settings.

#include "ABSpectator.h"
#include "GameFramework/SpectatorPawnMovement.h"
#include "VRCharacterMovementComponent.h"

AABSpectator::AABSpectator(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	bCanBeDamaged = false;
	bCollideWhenPlacing = false;

	VRMovementReference->GravityScale = 0;
	VRMovementReference->AirControl = 1;
	VRMovementReference->BrakingDecelerationFlying = 0.2;
	VRMovementReference->SetMovementMode(EMovementMode::MOVE_Flying);
	VRMovementReference->bCheatFlying = 0;
}


void AABSpectator::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("ForwardRH", this, &AABSpectator::MoveRH);
	PlayerInputComponent->BindAxis("RightRH", this, &AABSpectator::MoveRH);
	PlayerInputComponent->BindAxis("ForwardLH", this, &AABSpectator::MoveLH);
	PlayerInputComponent->BindAxis("RightLH", this, &AABSpectator::MoveLH);
}

void AABSpectator::MoveRH(float Value)
{
	ApplyMovement(RightMotionController);
}

void AABSpectator::MoveLH(float Value)
{
	ApplyMovement(LeftMotionController);
}

void AABSpectator::ApplyMovement(UGripMotionControllerComponent* Hand)
{
	float Right, Forward;
	if (!GetMovementAxisForHand(Right, Forward, Hand))
		return;

	FVector Direction = Right * Hand->GetRightVector() + Forward * Hand->GetForwardVector();
	GetMovementComponent()->AddInputVector(Direction, false);
}

void AABSpectator::PossessedBy(class AController* NewController)
{
	if (bReplicates)
	{
		Super::PossessedBy(NewController);
	}
	else
	{
		// We don't want the automatic changing of net role in Pawn code since we don't replicate, so don't call Super.
		AController* const OldController = Controller;
		Controller = NewController;

		// dispatch Blueprint event if necessary
		if (OldController != NewController)
		{
			ReceivePossessed(Controller);
		}
	}
}

