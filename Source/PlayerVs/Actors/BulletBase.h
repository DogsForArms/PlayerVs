// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletBase.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
class UAudioComponent;

UCLASS()
class PLAYERVS_API ABulletBase : public AActor
{
	GENERATED_BODY()

	virtual void PostInitializeComponents() override;
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const override;

	/** handle hit */
	UFUNCTION()
	void OnImpact(const FHitResult& HitResult);
	
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	UProjectileMovementComponent* MovementComp;

	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	USphereComponent* CollisionComp;

	UPROPERTY(EditAnywhere, Category = "Sound")
	UAudioComponent* ImpactSound;

	UPROPERTY(EditDefaultsOnly, Category = "WeaponStat")
	int32 HitDamage;

	UPROPERTY(EditDefaultsOnly, Category = "WeaponStat")
	TSubclassOf<UDamageType> DamageType;

public:	
	// Sets default values for this actor's properties
	ABulletBase();

	UFUNCTION()
	void InitializeBullet(float Velocity, AActor* Gun);

protected:
	UPROPERTY(Transient, ReplicatedUsing = OnRep_Exploded)
	bool bExploded;

	/** [client] explosion happened */
	UFUNCTION()
	void OnRep_Exploded();

private:	

	
	
};
