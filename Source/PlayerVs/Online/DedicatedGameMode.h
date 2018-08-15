// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Types/Types.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DedicatedGameMode.generated.h"

/**
 * 
 */
UCLASS(Config=Dedicated)
class PLAYERVS_API ADedicatedGameMode : public AGameModeBase
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

	UPROPERTY(Config)
	int32 RoundTime;

	UPROPERTY(Config)
	int32 MinimumPlayers;

	UPROPERTY(Config)
	int32 MaximumPlayers;

	UPROPERTY(Config)
	int32 TimeBetweenMatches;

	UPROPERTY(Config)
	int32 TimeBeforeMatch;

};
