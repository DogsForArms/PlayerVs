// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletBase.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
class UAudioComponent;

UCLASS()
class ALIENBETRAYAL_API ABulletBase : public AActor
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

public:	
	// Sets default values for this actor's properties
	ABulletBase();

	void InitializeBullet(float Velocity);

protected:
	UPROPERTY(Transient, ReplicatedUsing = OnRep_Exploded)
	bool bExploded;

	/** [client] explosion happened */
	UFUNCTION()
	void OnRep_Exploded();

private:	

	
	
};
