// Fill out your copyright notice in the Description page of Project Settings.

#include "GunBase.h"
#include "GripMotionControllerComponent.h"
#include "GameplayTagsManager.h"

// Sets default values
AGunBase::AGunBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGunBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGunBase::OnGrip_Implementation(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation)
{
	FGameplayTag HeldFreely = UGameplayTagsManager::Get().RequestGameplayTag(TEXT("Weapon.Gun.HeldFreely"));
	FGameplayTag HeldAtGrip = UGameplayTagsManager::Get().RequestGameplayTag(TEXT("Weapon.Gun.HeldAtGrip"));
	FGameplayTag DropOnTriggerRelease = UGameplayTagsManager::Get().RequestGameplayTag(TEXT("DropType.OnTriggerRelease"));
	FGameplayTag DropOnSideGrip = UGameplayTagsManager::Get().RequestGameplayTag(TEXT("DropType.OnSideGrip"));

	UE_LOG(LogTemp, Warning, TEXT("OnGrip_Implementation"))
	if (bWasSocketed)
	{
		FBPActorGripInformation GripInfo = GripInformation;
		DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		GrippingController->TeleportMoveGrip(GripInfo, true, true);
	}

	SetActorTickEnabled(true);

	if (GripInformation.bIsSlotGrip)
	{
		GameplayTags.RemoveTag(HeldFreely);
		GameplayTags.AddTag(HeldAtGrip);

		GameplayTags.RemoveTag(DropOnTriggerRelease);
		GameplayTags.AddTag(DropOnSideGrip);

		bCanBeFired = true;

		VRGripInterfaceSettings.SecondaryGripType = ESecondaryGripType::SG_SlotOnly;
	}
	else
	{
		GameplayTags.RemoveTag(HeldAtGrip);
		GameplayTags.AddTag(HeldFreely);

		GameplayTags.RemoveTag(DropOnSideGrip);
		GameplayTags.AddTag(DropOnTriggerRelease);

		bCanBeFired = false;

		VRGripInterfaceSettings.SecondaryGripType = ESecondaryGripType::SG_None;
	}
}

void AGunBase::OnGripRelease_Implementation(UGripMotionControllerComponent* ReleasingController, const FBPActorGripInformation& GripInformation, bool bWasSocketedValue)
{
	UE_LOG(LogTemp, Warning, TEXT("OnGripRelease_Implementation"));
	bWasSocketed = bWasSocketedValue;
	SetActorTickEnabled(true);
}

void AGunBase::OnUsed_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("OnUsed_Implementation PEW PEW"))
}

void AGunBase::OnEndUsed_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("OnEndUsed_Implementation PEW PEW"))
}

