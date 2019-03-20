// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraFunctionLibrary.h"
#include "BulletBase.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
class UAudioComponent;
class UNiagaraSystem;
class AImpactEffect;

UCLASS()
class PLAYERVS_API ABulletBase : public AActor
{
	GENERATED_BODY()

	virtual void PostInitializeComponents() override;
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const override;
	
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	UProjectileMovementComponent* MovementComp;

	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	USphereComponent* CollisionComp;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	TSubclassOf<AImpactEffect> ImpactTemplate;

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
	//////////////////////////////////////////////////////////////////////////
	// Death: Impact, Damage, Effects, Cleanup

	UFUNCTION()
	void OnImpact(const FHitResult& HitResult);

	UFUNCTION()
	void ApplyDamage(const FHitResult& Impact);

	UFUNCTION()
	void PlayHitEffect(const FHitResult& Impact);

	UFUNCTION()
	void DisableAndDestroy();

	UPROPERTY(Transient, ReplicatedUsing = OnRep_Exploded)
	bool bExploded;

	UFUNCTION()
	void OnRep_Exploded();

private:	

	class AActor* Gun;
	class APawn* GunOwner;
	
};
