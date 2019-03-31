// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Grippables/GrippableStaticMeshActor.h"
#include "VR/AttachmentInterface.h"
#include "PVGrippableStaticMeshActor.generated.h"

UCLASS()
class PLAYERVS_API APVGrippableStaticMeshActor : public AGrippableStaticMeshActor, public IAttachmentInterface
{
	GENERATED_BODY()

public:
	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const;

	void OnGrip_Implementation(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation) override;
	void OnGripRelease_Implementation(UGripMotionControllerComponent* ReleasingController, const FBPActorGripInformation& GripInformation, bool bWasSocketed) override;

	bool IsGripped();

//////////////////////////////////////////////////////////////////////////
// AttachmentInterface Management
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Attachment")
	void SetAttachmentManager(UObject* Manager);
	virtual void SetAttachmentManager_Implementation(UObject* Manager) override;

	UPROPERTY(Transient, ReplicatedUsing = OnRep_AttachmentManagerObject)
	UObject* AttachmentManagerObject;
	UFUNCTION()
	void OnRep_AttachmentManagerObject(UObject* LastManager);

	//UPROPERTY(Transient, ReplicatedUsing = OnRep_AttachmentManager)
	//TScriptInterface<IAttachmentManagerInterface> AttachmentManager;

	//UFUNCTION()
	//void OnRep_AttachmentManager(const TScriptInterface<IAttachmentManagerInterface>& LastManager);

	void SetOwner(AActor* NewOwner) override;

private:
	TWeakObjectPtr<UGripMotionControllerComponent> MotionController;

	void AttachmentChanged(UObject* Last, UObject* Current);
};
