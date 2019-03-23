// Fill out your copyright notice in the Description page of Project Settings.

#include "Magazine.h"
#include "Components/SphereComponent.h"
#include "PlayerVs.h"

AMagazine::AMagazine(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	bAlwaysRelevant = true;
	VRGripInterfaceSettings.MovementReplicationType = EGripMovementReplicationSettings::ForceClientSideMovement;
	VRGripInterfaceSettings.AdvancedGripSettings.bSetOwnerOnGrip = true;
	VRGripInterfaceSettings.AdvancedGripSettings.PhysicsSettings.bUsePhysicsSettings = true;
	VRGripInterfaceSettings.AdvancedGripSettings.PhysicsSettings.bTurnOffGravityDuringGrip = true;


	///////////////////
	// AttachmentPoint Setup
	UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(RootComponent);

	Mesh->SetCollisionObjectType(COLLISION_ATTACHMENT);
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	Mesh->SetCollisionResponseToChannel(COLLISION_ATTACHMENT, ECollisionResponse::ECR_Overlap);
	Mesh->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECollisionResponse::ECR_Ignore);

	Mesh->bMultiBodyOverlap = true;
	Mesh->SetNotifyRigidBodyCollision(true);
	Mesh->SetGenerateOverlapEvents(true);
	Mesh->bMultiBodyOverlap = true;
}

EMagazineType AMagazine::GetAttachmentType() const
{
	return EMagazineType::Pistol;
}