// Fill out your copyright notice in the Description page of Project Settings.

#include "PVGrippableStaticMeshActor.h"

void APVGrippableStaticMeshActor::OnGrip_Implementation(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation)
{
	Super::OnGrip_Implementation(GrippingController, GripInformation);
	MotionController = GrippingController;
	UE_LOG(LogTemp, Warning, TEXT("OnGrip_Implementation"))
}

void APVGrippableStaticMeshActor::OnGripRelease_Implementation(UGripMotionControllerComponent* ReleasingController, const FBPActorGripInformation& GripInformation, bool bWasSocketed)
{
	Super::OnGripRelease_Implementation(ReleasingController, GripInformation, bWasSocketed);
	MotionController = NULL;
	UE_LOG(LogTemp, Warning, TEXT("OnGripRelease_Implementation"))
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