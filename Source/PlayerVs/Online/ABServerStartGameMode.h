// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Types/Types.h"
#include "CoreMinimal.h"
#include "Online/ABGameMode.h"
#include "ABServerStartGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERVS_API AABServerStartGameMode : public AABGameMode
{
	GENERATED_BODY()
	
	
public:

	UFUNCTION(BlueprintCallable)
	FGameConfig ParseGameConfigFromCommandLine() const;
};
