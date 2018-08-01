// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/ABCharacterBase.h"
#include "ABSpectator.generated.h"


class  UGripMotionControllerComponent;
/**
 * 
 */
UCLASS()
class PLAYERVS_API AABSpectator : public AABCharacterBase
{
	GENERATED_BODY()
	
public:
	AABSpectator(const FObjectInitializer& ObjectInitializer);
	
protected:
	// Begin Pawn overrides
	/** Overridden to avoid changing network role. If subclasses want networked behavior, call the Pawn::PossessedBy() instead. */
	virtual void PossessedBy(class AController* NewController) override;
	// End Pawn overrides

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION()
	void MoveRH(float Value);
	UFUNCTION()
	void MoveLH(float Value);

	virtual void ApplyMovement(UGripMotionControllerComponent* Hand);
};
