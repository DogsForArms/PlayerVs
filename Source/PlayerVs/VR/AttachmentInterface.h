// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include "UObject/Interface.h"
#include "VR/AttachmentManagerInterface.h"

#include "AttachmentInterface.generated.h"

UINTERFACE(Blueprintable)
class PLAYERVS_API UAttachmentInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class PLAYERVS_API IAttachmentInterface
{
	GENERATED_IINTERFACE_BODY()

public:

	/* 
		Ask previous attachment manager to release.
		Ask current attachment manager to attach
	*/
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Attachment")
	void SetAttachmentManager(UObject* Manager);


};