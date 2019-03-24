// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include "UObject/Interface.h"

#include "AttachmentInterface.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttachmentFreed, AActor*, AttachedActor);

UINTERFACE(Blueprintable)
class PLAYERVS_API UAttachmentInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class PLAYERVS_API IAttachmentInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	FOnAttachmentFreed OnAttachmentFreed;
};