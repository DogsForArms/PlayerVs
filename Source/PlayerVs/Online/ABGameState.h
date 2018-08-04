// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "ABGameState.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERVS_API AABGameState : public AGameState
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Transient, Replicated)
	int32 RemainingTime;
	
	UPROPERTY(Transient, Replicated)
	bool bTimerPaused;
	
};
