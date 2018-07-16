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

UCLASS()
class ALIENBETRAYAL_API AGunBase : public AGrippableStaticMeshActor
{
	GENERATED_BODY()

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
	float BulletVelocity = 700;

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	UArrowComponent* Muzzle;

public:

	UPROPERTY(EditAnywhere, Category = "Sound")
	UAudioComponent* GunfireAudio;

public:	
	AGunBase();
	bool bCanBeFired;
	bool bWasSocketed;

	UFUNCTION(Unreliable, Client)
	void PlayGunEffects(bool bForce);
	void PlayGunEffects_Implementation(bool bForce);

private:

};
