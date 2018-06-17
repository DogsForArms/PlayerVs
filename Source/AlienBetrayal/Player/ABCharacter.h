// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRCharacter.h"
#include "ABCharacter.generated.h"

/**
 * 
 */
class UGripMotionControllerComponent;

UCLASS()
class ALIENBETRAYAL_API AABCharacter : public AVRCharacter
{
	GENERATED_BODY()

	AABCharacter();

	UFUNCTION(BlueprintCallable)
	void InitializeHands(UGripMotionControllerComponent* Left, UGripMotionControllerComponent* Right, USphereComponent* LeftGrab, USphereComponent* RightGrab);

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	UGripMotionControllerComponent* LeftHand;
	UPROPERTY()
	UGripMotionControllerComponent* RightHand;

	UPROPERTY()
	USphereComponent* LeftHandGrabArea;
	UPROPERTY()
	USphereComponent* RightHandGrabArea;

	UPROPERTY(EditAnywhere, Category = "Grip")
	float GripTraceLength;

public:
	void GrabLeft();
	void GrabRight();

	void GripDropOrUseObject(UGripMotionControllerComponent* Hand, USphereComponent* GrabArea, UGripMotionControllerComponent* OtherHand);

	UFUNCTION(Reliable, Server, WithValidation)
	void ServerTryGrab(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName);
	void ServerTryGrab_Implementation(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName);
	bool ServerTryGrab_Validate(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName);

	bool GetBoneTransform(FTransform& BoneTransform, UObject* ComponentOrActor, FName BoneName);

	void MoveForwardRH(float Value);
	void MoveRightRH(float Value);
	void MoveForwardLH(float Value);
	void MoveRightLH(float Value);
	void AddDpadMovementInput(FVector2D DPadDirection, UGripMotionControllerComponent* Hand);
};
