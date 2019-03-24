// Fill out your copyright notice in the Description page of Project Settings.

#include "PVGrippableStaticMeshActor.h"

void APVGrippableStaticMeshActor::OnGrip_Implementation(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation)
{
	UE_LOG(LogTemp, Warning, TEXT("Ethan OnGrip_Implementation %s"), *GetName())
	Super::OnGrip_Implementation(GrippingController, GripInformation);
	MotionController = GrippingController;
}

void APVGrippableStaticMeshActor::OnGripRelease_Implementation(UGripMotionControllerComponent* ReleasingController, const FBPActorGripInformation& GripInformation, bool bWasSocketed)
{
	UE_LOG(LogTemp, Warning, TEXT("Ethan OnGripRelease_Implementation %s"), *GetName())
	Super::OnGripRelease_Implementation(ReleasingController, GripInformation, bWasSocketed);
	MotionController = NULL;
}

bool APVGrippableStaticMeshActor::IsGripped()
{
	return MotionController->IsValidLowLevel();
}

void APVGrippableStaticMeshActor::Drop()
{
	if (MotionController->IsValidLowLevel())
	{
		MotionController->DropActor(this, true);
	}
}