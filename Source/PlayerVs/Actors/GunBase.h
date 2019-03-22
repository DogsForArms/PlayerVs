// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrippableStaticMeshActor.h"
#include "GunBase.generated.h"

class AGrippableStaticMeshActor;
class UGripMotionControllerComponent;
class ABulletBase;
class UArrowComponent;
class UAudioComponent;
class USphereComponent;

UCLASS()
class PLAYERVS_API AGunBase : public AGrippableStaticMeshActor
{
	GENERATED_BODY()

public:
	AGunBase(const FObjectInitializer& ObjectInitializer);

	virtual void OnGrip_Implementation(UGripMotionControllerComponent * GrippingController, const FBPActorGripInformation & GripInformation) override;
	virtual void OnGripRelease_Implementation(UGripMotionControllerComponent * ReleasingController, const FBPActorGripInformation & GripInformation, bool bWasSocketed = false) override;

	virtual void OnUsed_Implementation() override;
	virtual void OnEndUsed_Implementation() override;

	UFUNCTION(Reliable, Server, WithValidation)
	virtual void ServerFireGun(FVector Origin, FVector_NetQuantizeNormal ShootDir);
	virtual void ServerFireGun_Implementation(FVector Origin, FVector_NetQuantizeNormal ShootDir);
	virtual bool ServerFireGun_Validate(FVector Origin, FVector_NetQuantizeNormal ShootDir);

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

private:

};
