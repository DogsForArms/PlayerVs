// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/ABPlayerState.h"
#include "Types/Types.h"
#include "ABTTTPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERVS_API AABTTTPlayerState : public AABPlayerState
{
	GENERATED_BODY()

	AABTTTPlayerState();

private:
	TArray<AABPlayerState*> Traitors;

	ETeam Team = ETeam::Unassigned;

	bool bIsAlive = true;

	int32 InnocentsKilled = 0;

	int32 TraitorsKilled = 0;

	UFUNCTION(NetMulticast, Reliable)
	void All_Client_SetAll(ETeam Team, int32 InnocentsKilled, int32 TraitorsKilled, bool bIsAlive);

public:

	UFUNCTION(Client, Reliable)
	void Client_SetTeam(ETeam Value);

	UFUNCTION(Client, Reliable)
	void Client_SetTraitors(const TArray<class AABTTTPlayerState*>& Traitors);

	void RevealAll();

	void SetTeam(ETeam Value);

	UFUNCTION(BlueprintPure, Category = "Team")
	ETeam GetTeam() const;

	void SetIsAlive(bool Value);

	UFUNCTION(BlueprintCallable)
	bool GetIsAlive() const;

	void IncrementInnocentsKilled();
	void IncrementTraitorsKilled();

	UFUNCTION(BlueprintCallable)
	int32 GetInnocentsKilled() const;

	UFUNCTION(BlueprintCallable)
	int32 GetTraitorsKilled() const;

};
