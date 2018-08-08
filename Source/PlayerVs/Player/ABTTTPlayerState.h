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
	ETeam Team;

	bool bIsAlive = true;

public:

	UFUNCTION(Client, Reliable)
	void Client_SetTeam(ETeam Value);

	UFUNCTION(NetMulticast, Reliable)
	void All_Client_SetTeam(ETeam Value);

	void SetTeam(ETeam Value);

	UFUNCTION(BlueprintPure, Category = "Team")
	ETeam GetTeam() const;

	void SetIsAlive(bool Value);
	bool GetIsAlive() const;

};
