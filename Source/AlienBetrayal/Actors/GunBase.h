// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrippableStaticMeshActor.h"
#include "GunBase.generated.h"

class AGrippableStaticMeshActor;
class UGripMotionControllerComponent;

UCLASS()
class ALIENBETRAYAL_API AGunBase : public AGrippableStaticMeshActor
{
	GENERATED_BODY()

	virtual void OnGrip_Implementation(UGripMotionControllerComponent * GrippingController, const FBPActorGripInformation & GripInformation) override;
	virtual void OnGripRelease_Implementation(UGripMotionControllerComponent * ReleasingController, const FBPActorGripInformation & GripInformation, bool bWasSocketed = false) override;

	virtual void OnUsed_Implementation() override;
	virtual void OnEndUsed_Implementation() override;


public:	
	AGunBase();
	bool bCanBeFired;
	bool bWasSocketed;

protected:
	virtual void BeginPlay() override;

};
