// Fill out your copyright notice in the Description page of Project Settings.

#include "PVGrippableStaticMeshActor.h"
#include "Net/UnrealNetwork.h"
#include "VR/AttachmentManagerInterface.h"

void APVGrippableStaticMeshActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
//	DOREPLIFETIME(APVGrippableStaticMeshActor, AttachmentManager);
	DOREPLIFETIME(APVGrippableStaticMeshActor, AttachmentManagerObject);
}

void APVGrippableStaticMeshActor::OnGrip_Implementation(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation)
{
	UE_LOG(LogTemp, Warning, TEXT("Ethan OnGrip_Implementation %s"), *GetName())
	Super::OnGrip_Implementation(GrippingController, GripInformation);
	MotionController = GrippingController;
}

void APVGrippableStaticMeshActor::OnGripRelease_Implementation(UGripMotionControllerComponent* ReleasingController, const FBPActorGripInformation& GripInformation, bool bWasSocketed)
{
	Super::OnGripRelease_Implementation(ReleasingController, GripInformation, bWasSocketed);
	MotionController = NULL;
	UE_LOG(LogTemp, Warning, TEXT("xyz OnGripRelease_Implementation %s"), *GetName())
}


bool APVGrippableStaticMeshActor::IsGripped()
{
	return MotionController->IsValidLowLevel();
}

//////////////////////////////////////////////////////////////////////////
// AttachmentInterface Management

void APVGrippableStaticMeshActor::SetAttachmentManager_Implementation(const TScriptInterface<IAttachmentManagerInterface>& Manager)
{
	UObject* Last = AttachmentManagerObject;
	AttachmentChanged(Last, Manager.GetObject());
	AttachmentManagerObject = Manager.GetObject();
	// OnRep_AttachmentManagerObject(Last);
	//TScriptInterface< IAttachmentManagerInterface> LastManager = AttachmentManager;
	//AttachmentManager = Manager;
	//OnRep_AttachmentManager(LastManager);
}

void APVGrippableStaticMeshActor::OnRep_AttachmentManagerObject(UObject* Last)
{
	AttachmentChanged(Last, AttachmentManagerObject);
}

void APVGrippableStaticMeshActor::AttachmentChanged(UObject* Last, UObject* Current)
{
	TScriptInterface<IAttachmentManagerInterface> LastManager = Last;
	TScriptInterface<IAttachmentManagerInterface> CurrentManager = Current;

	if (IsGripped() && Current)
	{
		USceneComponent* Primitive = NULL;

		if (AActor* ParentActor = Cast<AActor>(Current))
		{
			Primitive = Cast<USceneComponent>(ParentActor->GetRootComponent());
		}
		else
		{
			Primitive = Cast<USceneComponent>(Current);
		}

		if (Primitive) {
			FTransform transform = FTransform(FRotator::ZeroRotator, FVector::ZeroVector, FVector::OneVector);
			MotionController->DropAndSocketObject(FTransform_NetQuantize(transform), this, 0, Primitive, NAME_None, true);
		}
		MotionController = NULL;
	}

	if (LastManager)
	{
		LastManager->Execute_Detach(LastManager.GetObject(), this);
	}

	if (CurrentManager)
	{
		CurrentManager->Execute_Attach(CurrentManager.GetObject(), this);
	}
}

//void APVGrippableStaticMeshActor::OnRep_AttachmentManager(const TScriptInterface<IAttachmentManagerInterface>& LastAttachmentManager)
//{
//	if (IsGripped())
//	{
//		Drop();
//	}
//
//	if (LastAttachmentManager)
//	{
//		LastAttachmentManager->Execute_Detach(LastAttachmentManager.GetObject(), this);
//		UE_LOG(LogTemp, Warning, TEXT("xyz OnRep_AttachmentManager Last.Detatch"))
//	}
//
//	if (AttachmentManager)
//	{
//		AttachmentManager->Execute_Attach(AttachmentManager.GetObject(), this);
//		UE_LOG(LogTemp, Warning, TEXT("xyz OnRep_AttachmentManager Current.Attach"))
//	}
//}