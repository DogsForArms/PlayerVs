// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrippableStaticMeshActor.h"
#include "VR/AttachmentManagerInterface.h"
#include "GunBase.generated.h"

class AGrippableStaticMeshActor;
class UGripMotionControllerComponent;
class ABulletBase;
class UArrowComponent;
class UAudioComponent;
class USphereComponent;
class AMagazine;

UCLASS()
class PLAYERVS_API AGunBase : public AGrippableStaticMeshActor, public IAttachmentManagerInterface
{
	GENERATED_BODY()

public:
	AGunBase(const FObjectInitializer& ObjectInitializer);

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

	virtual void OnGrip_Implementation(UGripMotionControllerComponent * GrippingController, const FBPActorGripInformation & GripInformation) override;
	virtual void OnGripRelease_Implementation(UGripMotionControllerComponent * ReleasingController, const FBPActorGripInformation & GripInformation, bool bWasSocketed = false) override;

	virtual void OnUsed_Implementation() override;
	virtual void OnEndUsed_Implementation() override;

	UFUNCTION(Reliable, Server, WithValidation)
	virtual void ServerFireGun(FVector Origin, FVector_NetQuantizeNormal ShootDir);
	virtual void ServerFireGun_Implementation(FVector Origin, FVector_NetQuantizeNormal ShootDir);
	virtual bool ServerFireGun_Validate(FVector Origin, FVector_NetQuantizeNormal ShootDir);

	virtual void Tick(float DeltaTime) override;
	virtual void TickGrip_Implementation(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation, float DeltaTime) override;

	UFUNCTION()
	void AttachMag();

	bool LoadedMagazineNeedsAttachment = false;

	UPROPERTY(EditAnywhere, Category = "Bullet")
	TSubclassOf<ABulletBase> BulletTemplate;

	UPROPERTY(EditAnywhere, Category = "Bullet")
	float BulletVelocity = 15000;

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	UArrowComponent* Muzzle;

	UPROPERTY(EditAnywhere, Category = "Sound")
	UAudioComponent* GunfireAudio;

	UPROPERTY(VisibleDefaultsOnly, Category = Attachment)
	USphereComponent* AttachmentPoint;

	UFUNCTION()
	void OnBeginOverlapMagazine(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void TryLoadMag(AActor* MaybeMag);


//////////////////////////////////////////////////////////////////////////
// Calculates Is Aiming & Movement Modifications
protected:
	// When gun is Aiming character's default movement speed gets multiplied by this [0,1] value.
	UPROPERTY(EditAnywhere, Category = "Movement")
	float AimMovementModifier = 0.5;

	// Decides when gun is Aiming - the cutoff angle in degrees between the Down vector and muzzle's Forward.
	UPROPERTY(EditAnywhere, Category = "Movement")
	float AimThreshold = 65.f;

	// Decides if gun is being aimed.
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CalculateIsAimed() const;

public:
	// Applies AimMovementModifier if gun IsBeingAimed
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float CalculateMovementModifier() const;

// Misc
public:	
	AGunBase();
	bool bCanBeFired;
	bool bWasSocketed;

	UFUNCTION(Unreliable, NetMulticast)
	void MulticastPlayGunEffects();
	void MulticastPlayGunEffects_Implementation();

	void PlayGunEffects();

	void OnRep_AttachmentReplication() override;

protected:

	AMagazine* LoadedMagazine;

//////////////////////////////////////////////////////////////////////////
// Attachment Manager Interface
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Attachment")
	void Attach(UObject* Attachment);
	virtual void Attach_Implementation(UObject* Attachment) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Attachment")
	void Detach(UObject* Attachment);
	virtual void Detach_Implementation(UObject* Attachment) override;

	FTimerHandle DebugMagTimer;

	FTimerHandle DeferredAttachment;
	UObject* DeferredAttachmentObject;
	UFUNCTION()
	void DeferredAttachmentHandle();

	int DebugMagTimerIterations;

	UFUNCTION()
	void DebugMagTimerHandle();

};
