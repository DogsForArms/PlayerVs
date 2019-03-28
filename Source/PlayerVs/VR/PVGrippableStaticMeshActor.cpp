// Fill out your copyright notice in the Description page of Project Settings.

#include "PVGrippableStaticMeshActor.h"
#include "Net/UnrealNetwork.h"
#include "VR/AttachmentManagerInterface.h"

void APVGrippableStaticMeshActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APVGrippableStaticMeshActor, AttachmentManager);
}

void APVGrippableStaticMeshActor::OnGrip_Implementation(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation)
{
	UE_LOG(LogTemp, Warning, TEXT("Ethan OnGrip_Implementation %s"), *GetName())
	Super::OnGrip_Implementation(GrippingController, GripInformation);
	MotionController = GrippingController;
}

void APVGrippableStaticMeshActor::OnGripRelease_Implementation(UGripMotionControllerComponent* ReleasingController, const FBPActorGripInformation& GripInformation, bool bWasSocketed)
{
	UE_LOG(LogTemp, Warning, TEXT("Ethan OnGripRelease_Implementation %s"), *GetName())
	Super::OnGripRelease_Implementation(ReleasingController, GripInformation, bWasSocketed);
	MotionController = NULL;
}

bool APVGrippableStaticMeshActor::IsGripped()
{
	return MotionController->IsValidLowLevel();
}

void APVGrippableStaticMeshActor::Drop()
{
	if (MotionController->IsValidLowLevel())
	{
		MotionController->DropActor(this, true);
	}
}

//////////////////////////////////////////////////////////////////////////
// AttachmentInterface Management

void APVGrippableStaticMeshActor::SetAttachmentManager_Implementation(const TScriptInterface<IAttachmentManagerInterface>& Manager)
{
	TScriptInterface< IAttachmentManagerInterface> LastManager = AttachmentManager;
	AttachmentManager = Manager;
	OnRep_AttachmentManager(LastManager);
}

void APVGrippableStaticMeshActor::OnRep_AttachmentManager(const TScriptInterface<IAttachmentManagerInterface>& LastAttachmentManager)
{
	if (IsGripped())
	{
		Drop();
	}

	if (LastAttachmentManager)
	{
		LastAttachmentManager->Detach(this);
		UE_LOG(LogTemp, Warning, TEXT("xyz OnRep_AttachmentManager Last.Detatch"))
	}

	if (AttachmentManager)
	{
		AttachmentManager->Attach(this);
		UE_LOG(LogTemp, Warning, TEXT("xyz OnRep_AttachmentManager Current.Attach"))
	}
}