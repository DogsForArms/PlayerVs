// Fill out your copyright notice in the Description page of Project Settings.

#include "ABCharacter.h"
#include "components/StaticMeshComponent.h"

void AABCharacter::InitializeHands(class UStaticMeshComponent* Left, class UStaticMeshComponent* Right)
{
	LeftHand = Left;
	RightHand = Right;
}

//////////////////////////////////////////////////////////////////////////
// Input

void AABCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Forward", this, &AABCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &AABCharacter::MoveRight);
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
}

void AABCharacter::GrabRight()
{
	UE_LOG(LogTemp, Warning, TEXT("GrabRight"))
}

void AABCharacter::MoveForward(float Value)
{

}

void AABCharacter::MoveRight(float Value)
{

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

void AABCharacter::AddDpadMovementInput(FVector2D DPadDirection, UStaticMeshComponent* Hand)
{
	FVector Up = FVector(0, 0, 1.f);
	FVector Forward = FVector::VectorPlaneProject(Hand->GetForwardVector(), Up).GetSafeNormal();
	FVector Right = FVector::VectorPlaneProject(Hand->GetRightVector(), Up).GetSafeNormal();
	FVector Direction = (Forward * DPadDirection.Y + Right * DPadDirection.X).GetSafeNormal();

	GetMovementComponent()->AddInputVector(Direction, false);
}

