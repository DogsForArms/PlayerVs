// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "Types/Types.h"
#include "CoreMinimal.h"
#include "ABServerStartGameMode.generated.h"

/**
 * 
 */
UCLASS(config=DedicatedServer)
class PLAYERVS_API AABServerStartGameMode : public AGameMode
{
	GENERATED_BODY()
	
	
public:

	UFUNCTION(BlueprintCallable)
	FGameConfig ParseGameConfigFromCommandLine() const;

	UPROPERTY(Config)
	FString ServerName;

	UPROPERTY(Config)
	FString Map;

	UPROPERTY(Config)
	FString Game;
};
