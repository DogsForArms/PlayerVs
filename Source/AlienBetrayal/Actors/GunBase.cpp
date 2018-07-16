// Fill out your copyright notice in the Description page of Project Settings.

#include "GunBase.h"
#include "GripMotionControllerComponent.h"
//#include "GameplayTagsManager.h"
#include "Actors/BulletBase.h"
#include "Components/ArrowComponent.h"
#include "DrawDebugHelpers.h"

//////////////////////////////////////////////////////////////////////////
// Initialization

AGunBase::AGunBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Muzzle = CreateDefaultSubobject<UArrowComponent>("Arrow");
	Muzzle->SetRelativeScale3D(FVector(0.2, 0.2, 0.2));
	Muzzle->SetupAttachment(RootComponent);

	GunfireAudio = CreateDefaultSubobject<UAudioComponent>("GunfireAudio");
	GunfireAudio->SetupAttachment(Muzzle);
	GunfireAudio->bAutoActivate = false;
}

//////////////////////////////////////////////////////////////////////////
// IVRGripInterface Overrides

void AGunBase::OnGrip_Implementation(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation)
{

}

void AGunBase::OnGripRelease_Implementation(UGripMotionControllerComponent* ReleasingController, const FBPActorGripInformation& GripInformation, bool bWasSocketedValue)
{
	UE_LOG(LogTemp, Warning, TEXT("OnGripRelease_Implementation"));
	bWasSocketed = bWasSocketedValue;
	SetActorTickEnabled(true);
}

void AGunBase::OnUsed_Implementation()
{
	FTransform WorldTransform = Muzzle->GetComponentToWorld();
	FVector Location = WorldTransform.GetLocation();
	FVector Forward = WorldTransform.GetRotation().Vector();

	ServerFireGun(Location, Forward);
	//TODO how to replicate to all clients except me.
	PlayGunEffects(true);
}

void AGunBase::OnEndUsed_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("OnEndUsed_Implementation PEW PEW"))
}

//////////////////////////////////////////////////////////////////////////
// Gun Methods

void AGunBase::ServerFireGun_Implementation(FVector Origin, FVector_NetQuantizeNormal ShootDir)
{
	if (!BulletTemplate)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot fire gun, not bullet specified."))
		return;
	}

	FTransform SpawnTM(ShootDir.Rotation(), Origin);
	ABulletBase* Bullet = Cast<ABulletBase>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, BulletTemplate, SpawnTM));
	if (Bullet)
	{
		Bullet->Instigator = Instigator;
		Bullet->SetOwner(this);
		Bullet->InitializeBullet(BulletVelocity);
		UGameplayStatics::FinishSpawningActor(Bullet, SpawnTM);
	}
}

bool AGunBase::ServerFireGun_Validate(FVector Origin, FVector_NetQuantizeNormal ShootDir)
{
	return true;
}

void AGunBase::PlayGunEffects_Implementation(bool bForce)
{
	if (!bForce /*&& !GunIsLocallyControlled*/) { return; }
	GunfireAudio->Play();
}
