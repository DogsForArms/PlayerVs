// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRCharacter.h"
#include "ABCharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERVS_API AABCharacterBase : public AVRCharacter
{
	GENERATED_BODY()
	
public:
	AABCharacterBase(const FObjectInitializer& ObjectInitializer);
	
protected:
	UFUNCTION()
	bool GetMovementAxisForHand(float& Right, float& Forward, UMotionControllerComponent* Hand);
};
