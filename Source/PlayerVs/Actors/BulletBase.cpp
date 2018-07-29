// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletBase.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/AudioComponent.h"
#include "Net/UnrealNetwork.h"
#include "PlayerVs.h"
#include "Player/ABCharacter.h"

// Sets default values
ABulletBase::ABulletBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	CollisionComp->InitSphereRadius(5.0f);
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

	RootComponent = CollisionComp;

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileComp");
	MovementComp->UpdatedComponent = CollisionComp;
	MovementComp->InitialSpeed = 2000.0f;
	MovementComp->MaxSpeed = 2000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->ProjectileGravityScale = 0.f;

	ImpactSound = CreateDefaultSubobject<UAudioComponent>("ImpactComponent");
	ImpactSound->bAutoActivate = false;
	ImpactSound->SetupAttachment(CollisionComp);

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

void ABulletBase::InitializeBullet(float Velocity, AActor* Gun)
{
	if (!MovementComp)
	{
		return;
	}

	AActor* GunOwner = Gun->GetOwner();
	UE_LOG(LogTemp, Warning, TEXT("InitializeBullet, gunOwner (%s) is %s"), *Gun->GetName(),*GunOwner->GetName())
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

void ABulletBase::OnImpact(const FHitResult& Impact)
{
	if (Role == ROLE_Authority && !bExploded)
	{
		bExploded = true;
		OnRep_Exploded();

		FPointDamageEvent PointDmg;
		PointDmg.DamageTypeClass = DamageType;
		PointDmg.HitInfo = Impact;
		//PointDmg.ShotDirection = ShootDir;
		PointDmg.Damage = HitDamage;

		Impact.GetActor()->TakeDamage(PointDmg.Damage, PointDmg, NULL, this);
	}
}

void ABulletBase::OnRep_Exploded()
{
	MovementComp->StopMovementImmediately();
	ImpactSound->Play();
	SetLifeSpan(2.0f);
}