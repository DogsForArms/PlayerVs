// Fill out your copyright notice in the Description page of Project Settings.

#include "PVGrippableStaticMeshActor.h"

void APVGrippableStaticMeshActor::OnGrip_Implementation(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation)
{
	UE_LOG(LogTemp, Warning, TEXT("Ethan OnGrip_Implementation %s"), *GetName())
	Super::OnGrip_Implementation(GrippingController, GripInformation);
	MotionController = GrippingController;

	FreeAttachmentClearAll();
}

void APVGrippableStaticMeshActor::OnGripRelease_Implementation(UGripMotionControllerComponent* ReleasingController, const FBPActorGripInformation& GripInformation, bool bWasSocketed)
{
	UE_LOG(LogTemp, Warning, TEXT("Ethan OnGripRelease_Implementation %s"), *GetName())
	Super::OnGripRelease_Implementation(ReleasingController, GripInformation, bWasSocketed);
	MotionController = NULL;

	//UPrimitiveComponent* Root = Cast<UPrimitiveComponent>(GetRootComponent());
	//if (Root)
	//{
	//	Root->SetSimulatePhysics(true);
	//}
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

void APVGrippableStaticMeshActor::FreeAttachmentClearAll()
{
	int test = 53;
	UE_LOG(LogTemp, Warning, TEXT("Ethan FreeAttachmentClearAll broadcast %s"), *GetName())
	OnAttachmentFreed.Broadcast(this);
	//	OnAttachmentFreed.Clear();
}