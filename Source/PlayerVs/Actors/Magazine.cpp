// Fill out your copyright notice in the Description page of Project Settings.

#include "Magazine.h"

AMagazine::AMagazine(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

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
}