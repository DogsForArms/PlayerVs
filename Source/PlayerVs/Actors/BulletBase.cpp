// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletBase.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/AudioComponent.h"
#include "Net/UnrealNetwork.h"
#include "PlayerVs.h"
#include "Player/ABCharacter.h"
#include "Effects/ImpactEffect.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABulletBase::ABulletBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	CollisionComp->InitSphereRadius(1.0f);
	CollisionComp->AlwaysLoadOnClient = true;
	CollisionComp->AlwaysLoadOnServer = true;
	CollisionComp->bTraceComplexOnMove = true;
	CollisionComp->SetNotifyRigidBodyCollision(true);
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComp->SetCollisionObjectType(COLLISION_PROJECTILE);
	CollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	CollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	CollisionComp->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECR_Ignore);
	CollisionComp->bReturnMaterialOnMove = true;

	RootComponent = CollisionComp;

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileComp");
	MovementComp->UpdatedComponent = CollisionComp;
	MovementComp->InitialSpeed = 2000.0f;
	MovementComp->MaxSpeed = 2000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->ProjectileGravityScale = 0.f;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
	SetRemoteRoleForBackwardsCompat(ROLE_SimulatedProxy);
	bReplicates = true;
	bReplicateMovement = true;

	HitDamage = 50.f;
	DamageType = UDamageType::StaticClass();
}

void ABulletBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABulletBase, bExploded);
}

void ABulletBase::InitializeBullet(float Velocity, AActor* FromGun)
{
	if (!MovementComp)
	{
		return;
	}

	Gun = FromGun;
	GunOwner = Cast<APawn>(Gun->GetOwner());

	MovementComp->InitialSpeed = Velocity;
	MovementComp->MaxSpeed = Velocity;
	CollisionComp->MoveIgnoreActors.Add(Gun);
}

void ABulletBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	MovementComp->OnProjectileStop.AddDynamic(this, &ABulletBase::OnImpact);
	SetLifeSpan(10.0f);
}

//////////////////////////////////////////////////////////////////////////
// Death: Impact, Damage, Effects, Cleanup

void ABulletBase::OnImpact(const FHitResult& Impact)
{
	if (Role == ROLE_Authority && !bExploded)
	{
		ApplyDamage(Impact);
		PlayHitEffect(Impact);
		DisableAndDestroy();
		bExploded = true;
	}
}

void ABulletBase::ApplyDamage(const FHitResult& Impact)
{
	if (Impact.GetActor())
	{
		FPointDamageEvent PointDmg;
		PointDmg.DamageTypeClass = DamageType;
		PointDmg.HitInfo = Impact;
		// PointDmg.ShotDirection = ShootDir;
		PointDmg.Damage = HitDamage;
		Impact.GetActor()->TakeDamage(PointDmg.Damage, PointDmg, GunOwner ? GunOwner->GetController() : NULL, this);
	}
}

void ABulletBase::PlayHitEffect(const FHitResult& Impact)
{
	if (GetNetMode() == ENetMode::NM_DedicatedServer) 
		return;

	if (ImpactTemplate)
	{
		const float NudgeConst = 2.0f;
		const FVector NudgedImpactLocation = Impact.ImpactPoint + Impact.ImpactNormal * NudgeConst;

		FTransform const SpawnTransform(Impact.ImpactNormal.Rotation(), NudgedImpactLocation);
		AImpactEffect* const EffectActor = GetWorld()->SpawnActorDeferred<AImpactEffect>(ImpactTemplate, SpawnTransform);
		if (EffectActor)
		{
			EffectActor->SurfaceHit = Impact;
			UGameplayStatics::FinishSpawningActor(EffectActor, SpawnTransform);
		}
	}
}

void ABulletBase::DisableAndDestroy()
{
	MovementComp->StopMovementImmediately();
	SetLifeSpan(2.0f);
}

void ABulletBase::OnRep_Exploded()
{
	// Scan ahead for likely impact, play effect.
	FVector ProjDirection = GetActorForwardVector();

	const FVector StartTrace = GetActorLocation() - ProjDirection * 200;
	const FVector EndTrace = GetActorLocation() + ProjDirection * 150;
	FHitResult Impact;

	if (!GetWorld()->LineTraceSingleByChannel(Impact, StartTrace, EndTrace, COLLISION_PROJECTILE, FCollisionQueryParams(SCENE_QUERY_STAT(ProjClient), true, Instigator)))
	{
		// failsafe
		Impact.ImpactPoint = GetActorLocation();
		Impact.ImpactNormal = -ProjDirection;
	}

	PlayHitEffect(Impact);
}