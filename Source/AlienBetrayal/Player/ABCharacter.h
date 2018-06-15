// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRCharacter.h"
#include "ABCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ALIENBETRAYAL_API AABCharacter : public AVRCharacter
{
	GENERATED_BODY()

	virtual void PostInitializeComponents() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	class UStaticMeshComponent* LeftHand;
	UPROPERTY()
	class UStaticMeshComponent* RightHand;

public:
	void GrabLeft();
	void GrabRight();
	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveForwardRH(float Value);
	void MoveRightRH(float Value);
	void MoveForwardLH(float Value);
	void MoveRightLH(float Value);
	
	
};
