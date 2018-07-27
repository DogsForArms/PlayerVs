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
class UStaticMeshComponent;

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

public: //Initialization
	AABCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void InitializeHands(USphereComponent* LeftGrab, USphereComponent* RightGrab);

	UFUNCTION()
	void OnBeginOverlapHolster(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlapHolster(
		UPrimitiveComponent* OverlappedComponent, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex);

	bool HandIsInHolster(UGripMotionControllerComponent* Hand);

	virtual void Tick(float DeltaTime) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	USphereComponent* LeftHandGrabArea;
	UPROPERTY()
	USphereComponent* RightHandGrabArea;

	bool bLeftHandIsInHolster;
	bool bRightHandIsInHolster;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* HolsterArea;

	UPROPERTY(EditAnywhere, Category = "Interaction")
	float GripTraceLength;

private: //VOIPTalker Setup
	FTimerHandle WaitForPlayerStateHandle;

	//if PlayerState, SetupTalker & clear timer
	UFUNCTION()
	void TrySetupTalker();

	UFUNCTION()
	void SetupTalker();

public: //Debugging
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Voice")
	UVOIPTalker* Talker;

public:
	// Voice Debugging (must be done in standalone).  bDrdopVoice will put your voice on the ground to test spatialization.
	// bLoopback loops your audio back to you.
	UFUNCTION(BlueprintCallable, Category = "Debug")
	void DebugVoice(bool bDropVoice, bool bLoopback);

public:
	void UpdateWidgetInteraction(UWidgetInteractionComponent* WidgetInteraction);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	UWidgetInteractionComponent* WidgetInteractionLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	UWidgetInteractionComponent* WidgetInteractionRight;

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

	UFUNCTION()
	void TryGrab(EControllerHand EHand, UObject* ObjectToGrip, FTransform_NetQuantize Transform, FName BoneName, bool bIsSlotGrip);

	UFUNCTION()
	void CallCorrectDropEvent(UGripMotionControllerComponent* Hand);

	UFUNCTION(Reliable, Server, WithValidation)
	void ServerTryDropAll(EControllerHand EHand);

	UFUNCTION()
	void TryDropAll(EControllerHand EHand);

	UFUNCTION()
	bool CanPutInInventory(AActor* Actor);

	UFUNCTION()
	void PutInInventory(AActor* Actor);

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
	UFUNCTION()
	FName GetPrimarySlotPrefix(UObject* ObjectToGrip, UGripMotionControllerComponent* Hand);

	UFUNCTION()
	FTransform GetHandRelativeTransformOfBoneOrObject(UGripMotionControllerComponent* Hand, UObject* ObjectToGrip, FTransform ObjectTransform, FName BoneName);
	
	UFUNCTION()
	bool GetBoneTransform(FTransform& BoneTransform, UObject* ComponentOrActor, FName BoneName);
	
	UFUNCTION()
	UGripMotionControllerComponent* GetHandReference(EControllerHand EHand);

	UFUNCTION()
	bool IsLocalGripOrDropEvent(UObject* ObjectToGrip);
};