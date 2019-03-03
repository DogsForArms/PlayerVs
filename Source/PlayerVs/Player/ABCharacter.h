// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Types/Types.h"
#include "CoreMinimal.h"
#include "Player/ABCharacterBase.h"
#include "ABCharacter.generated.h"
/**
 * 
 */
class UGripMotionControllerComponent;
class UVOIPTalker;
class UWidgetInteractionComponent;
class UStaticMeshComponent;

UCLASS()
class PLAYERVS_API AABCharacter : public AABCharacterBase
{
	GENERATED_BODY()

public: //Initialization
	AABCharacter(const FObjectInitializer& ObjectInitializer);

	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const;

	virtual void PostInitializeComponents() override;

	virtual void PreReplication(IRepChangedPropertyTracker & ChangedPropertyTracker) override;

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBeginOverlapHolster(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlapHolster(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	bool HandIsInHolster(UGripMotionControllerComponent* Hand);

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool bLeftHandIsInHolster;
	bool bRightHandIsInHolster;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* HolsterArea;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* Body;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* Head;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* LeftHandMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* RightHandMesh;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	USphereComponent* LeftHandGrabArea;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	USphereComponent* RightHandGrabArea;

	UPROPERTY(EditAnywhere, Category = "Interaction")
	float GripTraceLength;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float CalculateGunAimMovementModifier() const;


private: //VOIPTalker Setup
	FTimerHandle WaitForPlayerStateHandle;

	//if PlayerState, SetupTalker & clear timer
	UFUNCTION()
	void TrySetupTalker();

	UFUNCTION()
	void SetupTalker();

	// Temp storing the original walk speed from movement component
	float OriginalWalkSpeed;

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

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDropAll(EControllerHand EHand);

	UFUNCTION()
	void DropAll(EControllerHand EHand);

	UFUNCTION()
	bool CanPutInInventory(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	void PutInInventory(AActor* Actor);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerPutInInventory(AActor* GrippedActor, FTransform_NetQuantize transform);

	void UseLeft();
	void StopUseLeft();
	void UseRight();
	void StopUseRight();

	void ClientUse(UGripMotionControllerComponent* Hand, bool bPressed);

	void MoveRH(float Value);
	void MoveLH(float Value);
	void ApplyMovement(UGripMotionControllerComponent* Hand);

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

public:

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

	UPROPERTY(Transient, ReplicatedUsing = OnRep_Health)
	float Health;

	/** Identifies if pawn is in its dying state */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Health)
	uint32 bIsDying : 1;

	UFUNCTION()
	void OnRep_Health();

	/**
	* Kills pawn.  Server/authority only.
	* @param KillingDamage - Damage amount of the killing blow
	* @param DamageEvent - Damage event of the killing blow
	* @param Killer - Who killed this pawn
	* @param DamageCauser - the Actor that directly caused the damage (i.e. the Projectile that exploded, the Weapon that fired, etc)
	* @returns true if allowed
	*/
	virtual bool Die(float KillingDamage, struct FDamageEvent const& DamageEvent, class AController* Killer, class AActor* DamageCauser);

	/** Returns True if the pawn can die in the current state */
	virtual bool CanDie(float KillingDamage, FDamageEvent const& DamageEvent, class AController* Killer, class AActor* DamageCauser) const;

	/** Kill this pawn */
	virtual void KilledBy(class APawn* EventInstigator);

	virtual void FellOutOfWorld(const class UDamageType& dmgType);

protected:
	virtual void OnDeath(float KillingDamage, struct FDamageEvent const& DamageEvent, class APawn* InstigatingPawn, class AActor* DamageCauser);

	/** play effects on hit */
	virtual void PlayHit(float DamageTaken, struct FDamageEvent const& DamageEvent, class APawn* PawnInstigator, class AActor* DamageCauser);

	/** sets up the replication for taking a hit */
	void ReplicateHit(float Damage, struct FDamageEvent const& DamageEvent, class APawn* InstigatingPawn, class AActor* DamageCauser, bool bKilled);

	// gets modified in ReplicateHit
	/** Replicate where this pawn was last hit and damaged */
	UPROPERTY(Transient, ReplicatedUsing = OnRep_LastTakeHitInfo)
	struct FTakeHitInfo LastTakeHitInfo;

	/** play hit or death on client */
	UFUNCTION()
	void OnRep_LastTakeHitInfo();

	float LastTakeHitTimeTimeout;
};