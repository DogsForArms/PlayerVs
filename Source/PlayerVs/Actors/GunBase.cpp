// Fill out your copyright notice in the Description page of Project Settings.

#include "GunBase.h"
#include "GripMotionControllerComponent.h"
//#include "GameplayTagsManager.h"
#include "Actors/BulletBase.h"
#include "Components/ArrowComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerVs.h"
#include "Actors/Magazine.h"
//////////////////////////////////////////////////////////////////////////
// Initialization

AGunBase::AGunBase(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	Muzzle = CreateDefaultSubobject<UArrowComponent>("Arrow");
	Muzzle->SetRelativeScale3D(FVector(0.2, 0.2, 0.2));
	Muzzle->SetupAttachment(RootComponent);

	GunfireAudio = CreateDefaultSubobject<UAudioComponent>("GunfireAudio");
	GunfireAudio->SetupAttachment(Muzzle);
	GunfireAudio->bAutoActivate = false;

	bAlwaysRelevant = true;
	VRGripInterfaceSettings.MovementReplicationType = EGripMovementReplicationSettings::ForceClientSideMovement;
	VRGripInterfaceSettings.AdvancedGripSettings.bSetOwnerOnGrip = true;
	VRGripInterfaceSettings.AdvancedGripSettings.PhysicsSettings.bUsePhysicsSettings = true;
	VRGripInterfaceSettings.AdvancedGripSettings.PhysicsSettings.bTurnOffGravityDuringGrip = true;

	UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(RootComponent);

	Mesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	Mesh->SetNotifyRigidBodyCollision(true);
	Mesh->SetGenerateOverlapEvents(true);
	Mesh->bMultiBodyOverlap = true;

	///////////////////
	// AttachmentPoint Setup
	AttachmentPoint = CreateDefaultSubobject<USphereComponent>("AttachmentPoint");
	AttachmentPoint->InitSphereRadius(2.5f);
	AttachmentPoint->AlwaysLoadOnClient = false;
	AttachmentPoint->AlwaysLoadOnServer = true;

	AttachmentPoint->SetCollisionObjectType(COLLISION_ATTACHMENT);
	AttachmentPoint->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	AttachmentPoint->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	AttachmentPoint->SetCollisionResponseToChannel(COLLISION_ATTACHMENT, ECollisionResponse::ECR_Overlap);

	AttachmentPoint->SetGenerateOverlapEvents(true);
	AttachmentPoint->bMultiBodyOverlap = true;
	AttachmentPoint->OnComponentBeginOverlap.AddDynamic(this, &AGunBase::OnBeginOverlapMagazine);

	AttachmentPoint->SetupAttachment(RootComponent);
}

void AGunBase::OnBeginOverlapMagazine(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	AMagazine* Magazine = Cast<AMagazine>(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("xyz otherActor is %s"), (OtherActor ? *OtherActor->GetName() : TEXT("NULL")))
	if (Magazine) 
	{
		// Do it
		UE_LOG(LogTemp, Warning, TEXT("xyz Magazine is in gun! '%s'"), *OtherActor->GetName() )
		if (Magazine->GetAttachmentType() == EMagazineType::Pistol)
		{
			UE_LOG(LogTemp, Warning, TEXT("xyz YES!"))
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// IVRGripInterface Overrides

void AGunBase::OnGrip_Implementation(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation)
{
	Super::OnGrip_Implementation(GrippingController, GripInformation);
}

void AGunBase::OnGripRelease_Implementation(UGripMotionControllerComponent* ReleasingController, const FBPActorGripInformation& GripInformation, bool bWasSocketedValue)
{
	Super::OnGripRelease_Implementation(ReleasingController, GripInformation, bWasSocketed);
	UE_LOG(LogTemp, Warning, TEXT("OnGripRelease_Implementation"));
	bWasSocketed = bWasSocketedValue;
	SetActorTickEnabled(true);
}

void AGunBase::OnUsed_Implementation()
{
	Super::OnUsed_Implementation();
	FTransform WorldTransform = Muzzle->GetComponentToWorld();
	FVector Location = WorldTransform.GetLocation();
	FVector Forward = WorldTransform.GetRotation().Vector();

	ServerFireGun(Location, Forward);
	//TODO how to replicate to all clients except me.
	PlayGunEffects();
}

void AGunBase::OnEndUsed_Implementation()
{
	Super::OnEndUsed_Implementation();
	UE_LOG(LogTemp, Warning, TEXT("Gun OnEndUsed_Implementation PEW PEW"))
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
		Bullet->InitializeBullet(BulletVelocity, this);
		UGameplayStatics::FinishSpawningActor(Bullet, SpawnTM);
		MulticastPlayGunEffects();
	}
}

bool AGunBase::ServerFireGun_Validate(FVector Origin, FVector_NetQuantizeNormal ShootDir)
{
	return true;
}

void AGunBase::MulticastPlayGunEffects_Implementation()
{
	APlayerController *OwningController = GetNetOwningPlayer()->GetPlayerController(GetWorld());
	if (OwningController && !OwningController->IsLocalController()) {
		return;
	}
	PlayGunEffects();
}

void AGunBase::PlayGunEffects()
{
	GunfireAudio->Play();
}

//////////////////////////////////////////////////////////////////////////
// Calculates Is Aiming & Movement Modifications
bool AGunBase::CalculateIsAimed() const
{
	float DegreesFromGroundToMuzzle = FMath::RadiansToDegrees(
		FMath::Acos(
			FVector::DotProduct(FVector(0.f, 0.f, -1.f), Muzzle->GetForwardVector())
		)
	);
	return DegreesFromGroundToMuzzle > AimThreshold;
}

float AGunBase::CalculateMovementModifier() const
{
	return CalculateIsAimed() ? AimMovementModifier : 1.f;
}
