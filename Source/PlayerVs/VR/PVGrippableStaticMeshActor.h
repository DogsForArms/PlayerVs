// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Grippables/GrippableStaticMeshActor.h"
#include "VR/AttachmentInterface.h"
#include "PVGrippableStaticMeshActor.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERVS_API APVGrippableStaticMeshActor : public AGrippableStaticMeshActor, public IAttachmentInterface
{
	GENERATED_BODY()

public:

	void OnGrip_Implementation(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation) override;
	void OnGripRelease_Implementation(UGripMotionControllerComponent* ReleasingController, const FBPActorGripInformation& GripInformation, bool bWasSocketed) override;

	bool IsGripped();
	void Drop();

private:
	TWeakObjectPtr<UGripMotionControllerComponent> MotionController;
};
