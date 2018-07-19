// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRCharacter.h"
#include "ABCharacter.generated.h"
/**
 * 
 */
class UGripMotionControllerComponent;
class UVOIPTalker;
class UWidgetInteractionComponent;

USTRUCT()
struct FGrabScanResult
{
	GENERATED_BODY()

	UPROPERTY()
	FName BoneName;

	UPROPERTY()
	FVector ImpactPoint;

	UPROPERTY()
	UObject* ObjectToGrip;

	UPROPERTY()
	FTransform ObjectTransform;

	UPROPERTY()
	AActor* Actor;

	UPROPERTY()
	UPrimitiveComponent* Component;

	FGrabScanResult()
	{
		BoneName = FName("None");
		ImpactPoint = FVector::ZeroVector;
		ObjectToGrip = NULL;
		Actor = NULL;
		Component = NULL;
	}
};

UCLASS()
class PLAYERVS_API AABCharacter : public AVRCharacter
{
	GENERATED_BODY()

	AABCharacter();

	UFUNCTION(BlueprintCallable)
	void InitializeHands(USphereComponent* LeftGrab, USphereComponent* RightGrab);

	void SetupTalker();
	void OnRep_PlayerState() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	USphereComponent* LeftHandGrabArea;
	UPROPERTY()
	USphereComponent* RightHandGrabArea;

	UPROPERTY(EditAnywhere, Category = "Interaction")
	UWidgetInteractionComponent* WidgetInteractionLeft;

	UPROPERTY(EditAnywhere, Category = "Interaction")
	UWidgetInteractionComponent* WidgetInteractionRight;

	UPROPERTY(EditAnywhere, Category = "Interaction")
	float GripTraceLength;

	virtual void Tick(float DeltaTime) override;

	void UpdateWidgetInteraction(UWidgetInteractionComponent* WidgetInteraction);

public:
	// Voice Debugging (must be done in standalone).  bDrdopVoice will put your voice on the ground to test spacialization.
	// bLoopback loops your audio back to you.
	UFUNCTION(BlueprintCallable, Category = "Debug")
	void DebugVoice(bool bDropVoice, bool bLoopback);

public:

	UPROPERTY(EditAnywhere, Category = "Voice")
	UVOIPTalker* Talker;

	UFUNCTION(BlueprintCallable)
	void GrabLeft();

	UFUNCTION(BlueprintCallable)
	void GrabRight();

	UFUNCTION()
	bool GetGrabScanResults(TArray<FGrabScanResult> &OutResults, USphereComponent* GrabArea);
	
	UFUNCTION()
	void GripDropOrUseObject(UGripMotionControllerComponent* Hand, USphereComponent* GrabArea, UGripMotionControllerComponent* OtherHand);

	UFUNCTION()
	bool UseWidget(UGripMotionControllerComponent* Hand, bool bClick);

	UFUNCTION()
	void CallCorrectGrabEvent(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName, bool bIsSlotGrip);

	UFUNCTION(Reliable, Server, WithValidation)
	void ServerTryGrab(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName, bool bIsSlotGrip);
	void ServerTryGrab_Implementation(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName, bool bIsSlotGrip);
	bool ServerTryGrab_Validate(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName, bool bIsSlotGrip);

	UFUNCTION()
	void TryGrab(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName, bool bIsSlotGrip);

	UFUNCTION()
	void CallCorrectDropEvent(UGripMotionControllerComponent* Hand);

	UFUNCTION(Reliable, Server, WithValidation)
	void ServerTryDropAll(EControllerHand EHand);
	void ServerTryDropAll_Implementation(EControllerHand EHand);
	bool ServerTryDropAll_Validate(EControllerHand EHand);

	UFUNCTION()
	void TryDropAll(EControllerHand EHand);

	void UseLeft();
	void StopUseLeft();
	void UseRight();
	void StopUseRight();

	void ClientUse(UGripMotionControllerComponent* Hand, bool bPressed);

	void MoveForwardRH(float Value);
	void MoveRightRH(float Value);
	void MoveForwardLH(float Value);
	void MoveRightLH(float Value);
	void AddDpadMovementInput(FVector2D DPadDirection, UGripMotionControllerComponent* Hand);

private:
	FName GetPrimarySlotPrefix(UObject* ObjectToGrip, UGripMotionControllerComponent* Hand);
	FTransform GetHandRelativeTransformOfBoneOrObject(UGripMotionControllerComponent* Hand, UObject* ObjectToGrip, FTransform ObjectTransform, FName BoneName);
	bool GetBoneTransform(FTransform& BoneTransform, UObject* ComponentOrActor, FName BoneName);
	
	UGripMotionControllerComponent* GetHandReference(EControllerHand EHand);

	bool IsLocalGripOrDropEvent(UObject* ObjectToGrip);
};