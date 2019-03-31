// Fill out your copyright notice in the Description page of Project Settings.

#include "GunBase.h"
#include "GripMotionControllerComponent.h"
//#include "GameplayTagsManager.h"
#include "Actors/BulletBase.h"
#include "Components/SceneComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "Components/PrimitiveComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerVs.h"
#include "Actors/Magazine.h"
#include "Net/UnrealNetwork.h"
#include "VR/AttachmentInterface.h"
#include "Debug.h"
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
	AttachmentPoint->InitSphereRadius(2.5f); //1
	AttachmentPoint->AlwaysLoadOnClient = false;
	AttachmentPoint->AlwaysLoadOnServer = true;

	AttachmentPoint->SetCollisionObjectType(ECC_WorldDynamic);
	AttachmentPoint->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	AttachmentPoint->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	AttachmentPoint->SetCollisionResponseToChannel(COLLISION_ATTACHMENT, ECollisionResponse::ECR_Overlap);

	AttachmentPoint->SetGenerateOverlapEvents(true);
	AttachmentPoint->bMultiBodyOverlap = true;
	AttachmentPoint->OnComponentBeginOverlap.AddDynamic(this, &AGunBase::OnBeginOverlapMagazine);

	AttachmentPoint->SetupAttachment(RootComponent);
}


void AGunBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	//DOREPLIFETIME(AGunBase, LoadedMagazine);
}

void AGunBase::OnBeginOverlapMagazine(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	TryLoadMag(OtherActor);
}

void AGunBase::TryLoadMag(AActor* MaybeMag)
{
	AMagazine* Magazine = Cast<AMagazine>(MaybeMag);
	TScriptInterface<IAttachmentInterface> MagAttachment = Magazine;
	if ((!Magazine || Magazine->GetAttachmentType() != EMagazineType::Pistol) ||
		(Role != ROLE_Authority) ||
		(LoadedMagazine)) //temporary, only allow loaded magazine
		return;
	UE_LOG(LogTemp, Warning, TEXT("+++++++++++++++++++++++++++++++++++++++++++++ %s <-> %s"), *UDebug::NameOrNull(Magazine), *UDebug::NameOrNull(this));
	UE_LOG(LogTemp, Warning, TEXT("TryLoadMag Pre SetAttachmentManager Mag %s"), *UDebug::ActorDebugNet(Magazine));
	MagAttachment->Execute_SetAttachmentManager(MagAttachment.GetObject(), this);
	UE_LOG(LogTemp, Warning, TEXT("TryLoadMag Post SetAttachmentManager Mag %s"), *UDebug::ActorDebugNet(Magazine));
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

//////////////////////////////////////////////////////////////////////////
// Attachment Manager Interface

void AGunBase::DeferredAttachmentHandle()
{
	AActor* Actor = Cast<AActor>(DeferredAttachmentObject);
	if (!Actor) return;

	UPrimitiveComponent* OtherRoot = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
	UPrimitiveComponent* MyRoot = Cast<UPrimitiveComponent>(GetRootComponent());

	if (MyRoot) {
		MyRoot->MoveIgnoreActors.Add(Actor);
	}

	//Actor->SetReplicates(false);
	//Actor->SetReplicateMovement(false);
	//AGrippableStaticMeshActor* Grippable = Cast<AGrippableStaticMeshActor>(Actor);
	//if (Grippable) {
	//	Grippable->bReplicateMovement = false;
	//	Grippable->bStaticMeshReplicateMovement = false;
	//}
	//Actor->TearOff();

	OtherRoot->AttachToComponent(MyRoot,
		FAttachmentTransformRules(
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::KeepWorld,
			true)
	);
	//Actor->SetActorRelativeTransform(FTransform(FRotator::ZeroRotator, FVector::ZeroVector, FVector::OneVector), false, 0, ETeleportType::ResetPhysics);

	if (AMagazine * Mag = Cast<AMagazine>(Actor))
	{
		LoadedMagazine = Mag;
	}

	DebugMagTimerIterations = 3;
	DebugMagTimerHandle();
	GetWorld()->GetTimerManager().SetTimer(DebugMagTimer, this, &AGunBase::DebugMagTimerHandle, 0.01f, true);
}

void AGunBase::Attach_Implementation(UObject* ActorMaybe)
{
	DeferredAttachmentObject = ActorMaybe;
	DeferredAttachmentHandle();
	//GetWorld()->GetTimerManager().SetTimer(DeferredAttachment, this, &AGunBase::DeferredAttachmentHandle, 2.0f, false);
}

void AGunBase::DebugMagTimerHandle()
{
	UE_LOG(LogTemp, Warning, TEXT("========== %s"), *UDebug::GetNetModeName(GetNetMode()));
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *UDebug::ActorNetRole(this));
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *UDebug::ActorNetRole(LoadedMagazine));

	UE_LOG(LogTemp, Warning, TEXT("gun %s"), *UDebug::ActorNetRole(this));
	UE_LOG(LogTemp, Warning, TEXT("gun owner %s"), *UDebug::ActorNetRole(this->GetOwner()));

	UE_LOG(LogTemp, Warning, TEXT("mag %s"), *UDebug::ActorNetRole(LoadedMagazine));
	UE_LOG(LogTemp, Warning, TEXT("mag owner %s"), *UDebug::ActorNetRole(LoadedMagazine->GetOwner()));

	//UPrimitiveComponent* PrimitiveMag = Cast<UPrimitiveComponent>(LoadedMagazine ? LoadedMagazine->GetRootComponent() : NULL);
	//FString MagIsSimulating = PrimitiveMag ? UDebug::BoolToString(PrimitiveMag->IsSimulatingPhysics()) : FString("NULL");
	//UE_LOG(LogTemp, Warning, TEXT("%s simulatephysics %s"), *UDebug::NameOrNull(LoadedMagazine), *MagIsSimulating)

	//UE_LOG(LogTemp, Warning, TEXT("%s net owner is "), *UDebug::NameOrNull(this), *UDebug::NameOrNull(this->GetNetOwner()));
	//UE_LOG(LogTemp, Warning, TEXT("%s net owner is %s"), *UDebug::NameOrNull(LoadedMagazine), *UDebug::NameOrNull(LoadedMagazine->GetNetOwner()));
	//FVector Delta = (LoadedMagazine ? LoadedMagazine->GetActorLocation() : GetActorLocation()) - GetActorLocation();
	//UE_LOG(LogTemp, Warning, TEXT("Vector Offset %s"), *Delta.ToString());
	UE_LOG(LogTemp, Warning, TEXT("=========="));

	DebugMagTimerIterations--;
	if (DebugMagTimerIterations <= 0) {
		GetWorld()->GetTimerManager().ClearTimer(DebugMagTimer);
	}
}

void AGunBase::Detach_Implementation(UObject* ActorMaybe)
{
	AActor* Actor = Cast<AActor>(ActorMaybe);
	if (!Actor) return;

	UPrimitiveComponent* OtherRoot = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
	UPrimitiveComponent* MyRoot = Cast<UPrimitiveComponent>(GetRootComponent());

	Actor->DetachFromActor(
		FDetachmentTransformRules(
			FAttachmentTransformRules(
				EAttachmentRule::KeepWorld,
				EAttachmentRule::KeepWorld,
				EAttachmentRule::KeepWorld,
				true),
			true)
	);

	if (MyRoot) {
		MyRoot->MoveIgnoreActors.Remove(Actor);
	}

	//Actor->SetReplicateMovement(true);
	//AGrippableStaticMeshActor* Grippable = Cast<AGrippableStaticMeshActor>(Actor);
	//if (Grippable) {
	//	Grippable->bReplicateMovement = true;
	//	//Grippable->bStaticMeshReplicateMovement = true;
	//}
	//OtherRoot->SetSimulatePhysics(true);
	//OtherRoot->SetEnableGravity(true);

	UE_LOG(LogTemp, Warning, TEXT("xyz Detach_Implementation (%s) %s to %s "), *UDebug::GetNetModeName(GetNetMode()), *ActorMaybe->GetName(), *GetName())

}

void AGunBase::OnRep_AttachmentReplication()
{
	Super::OnRep_AttachmentReplication();
}