// Fill out your copyright notice in the Description page of Project Settings.

#include "ABCharacter.h"
#include "components/StaticMeshComponent.h"

void AABCharacter::PostInitializeComponents()
{
	TSubclassOf<UStaticMeshComponent> MeshType;
	auto Any = GetComponentsByClass(MeshType);
	auto Left = GetComponentsByTag(MeshType, FName("Left"));
	auto Right = GetComponentsByTag(MeshType, FName("Right"));
	if (Left.Num() && Right.Num()) {
		LeftHand = Cast<UStaticMeshComponent>(Left[0]);
		RightHand = Cast<UStaticMeshComponent>(Right[0]);
	}
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

}

void AABCharacter::MoveRightRH(float Value)
{

}
void AABCharacter::MoveForwardLH(float Value)
{

}

void AABCharacter::MoveRightLH(float Value)
{

}

