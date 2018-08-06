// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/ABPlayerState.h"
#include "ABDeathMatchPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERVS_API AABDeathMatchPlayerState : public AABPlayerState
{
	GENERATED_BODY()

protected:

	UPROPERTY(Replicated)
	int NumKills;
	UPROPERTY(Replicated)
	int NumDeaths;
public:
	void ScoreKill(AABDeathMatchPlayerState* Victim);
	void ScoreDeath(AABDeathMatchPlayerState* KilledBy);

	UFUNCTION(BlueprintCallable, Category = "Score")
	int GetNumKills() const;

	UFUNCTION(BlueprintCallable, Category = "Score")
	int GetNumDeaths() const;
};
