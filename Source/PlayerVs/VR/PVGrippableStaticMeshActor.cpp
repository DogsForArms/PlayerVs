// Fill out your copyright notice in the Description page of Project Settings.

#include "PVGrippableStaticMeshActor.h"
#include "Net/UnrealNetwork.h"
#include "VR/AttachmentManagerInterface.h"
#include "Debug.h"

void APVGrippableStaticMeshActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
//	DOREPLIFETIME(APVGrippableStaticMeshActor, AttachmentManager);
	DOREPLIFETIME(APVGrippableStaticMeshActor, AttachmentManagerObject);
}

void APVGrippableStaticMeshActor::OnGrip_Implementation(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation)
{
	UE_LOG(LogTemp, Warning, TEXT("APVGrippableStaticMeshActor OnGrip_Implementation %s"), *UDebug::ActorDebugNet(this));
	Super::OnGrip_Implementation(GrippingController, GripInformation);
	//MotionController = GrippingController;

	if (HasAuthority())
	{
		SetAttachmentManager_Implementation(GrippingController);
	}
}

void APVGrippableStaticMeshActor::OnGripRelease_Implementation(UGripMotionControllerComponent* ReleasingController, const FBPActorGripInformation& GripInformation, bool bWasSocketed)
{
	Super::OnGripRelease_Implementation(ReleasingController, GripInformation, bWasSocketed);
	//MotionController = NULL;
	UE_LOG(LogTemp, Warning, TEXT("APVGrippableStaticMeshActor OnGripRelease_Implementation %s"), *UDebug::ActorDebugNet(this));
	
	//if (HasAuthority())
	//{
	//	SetAttachmentManager_Implementation(NULL);
	//}
}

bool APVGrippableStaticMeshActor::IsGripped()
{
	return MotionController->IsValidLowLevel() && MotionController->GetIsHeld(this);
}

//////////////////////////////////////////////////////////////////////////
// AttachmentInterface Management

void APVGrippableStaticMeshActor::SetAttachmentManager_Implementation(UObject* Manager)
{
	UObject* Last = AttachmentManagerObject;
	AttachmentChanged(Last, Manager);
	AttachmentManagerObject = Manager;
}

void APVGrippableStaticMeshActor::OnRep_AttachmentManagerObject(UObject* Last)
{
	AttachmentChanged(Last, AttachmentManagerObject);
}

void APVGrippableStaticMeshActor::AttachmentChanged(UObject* Last, UObject* Current)
{
	UE_LOG(LogTemp, Warning, TEXT("Begin AttachmentChanged %s"), *UDebug::ActorDebugNet(this));

	TScriptInterface<IAttachmentManagerInterface> LastManager = Last;
	TScriptInterface<IAttachmentManagerInterface> CurrentManager = Current;

	UGripMotionControllerComponent* LastMotionController = Cast<UGripMotionControllerComponent>(Last);

	if (LastMotionController && Current && (GetNetMode() == ENetMode::NM_ListenServer || GetNetMode() == ENetMode::NM_DedicatedServer))
	{
		USceneComponent* Primitive = NULL;

		if (AActor * ParentActor = Cast<AActor>(Current))
		{
			Primitive = Cast<USceneComponent>(ParentActor->GetRootComponent());
		}
		else
		{
			Primitive = Cast<USceneComponent>(Current);
		}

		if (Primitive) {
			FTransform transform = FTransform(FRotator::ZeroRotator, FVector::ZeroVector, FVector::OneVector);
			LastMotionController->DropAndSocketObject(FTransform_NetQuantize(transform), this, 0, Primitive, NAME_None, true);
			this->CopyRemoteRoleFrom(this->GetOwner());

			UE_LOG(LogTemp, Warning, TEXT("AttachmentChanged setting remote role from owner"));
			//LastMotionController->DropActor(this, true);
		}
	}

	if (LastManager)
	{
		LastManager->Execute_Detach(LastManager.GetObject(), this);
	}

	if (CurrentManager)
	{
		CurrentManager->Execute_Attach(CurrentManager.GetObject(), this);
	}

	UE_LOG(LogTemp, Warning, TEXT("End AttachmentChanged %s"), *UDebug::ActorDebugNet(this));
}

void APVGrippableStaticMeshActor::SetOwner(AActor* NewOwner)
{
	Super::SetOwner(NewOwner);
}