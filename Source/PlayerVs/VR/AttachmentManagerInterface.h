// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include "UObject/Interface.h"

#include "AttachmentManagerInterface.generated.h"

class UObject;

UINTERFACE(Blueprintable)
class PLAYERVS_API UAttachmentManagerInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class PLAYERVS_API IAttachmentManagerInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Attachment")
	void Attach(UObject* Attachment);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Attachment")
	void Detach(UObject* Attachment);

};