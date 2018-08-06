// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Online/ABGameMode.h"
#include "ABTTTGameMode.generated.h"


class AController;
class UDamageType;
/**
 * 
 */
UCLASS()
class PLAYERVS_API AABTTTGameMode : public AABGameMode
{
	GENERATED_UCLASS_BODY()

	virtual void HandleMatchHasStarted() override;
	
protected:
	/**
		Assign PlayerStates to Alien team,
		Alien Count must be <= NumPlayers!
	*/
	void AssignAliens(int AlienCount);

	/**
		PlayerStates that Unassigned will be set to Innocent
	*/
	void UnassignedToInnocent();

	virtual void HandleMatchHasEnded() override;

public:
	virtual void Killed(AController* Killer, AController* KilledPlayer, APawn* KilledPawn, const UDamageType* DamageType) override;
	
	virtual bool GameCanStartCountdown() override;

protected:
	virtual void DetermineMatchWinner() override;

	virtual	bool IsWinner(AABPlayerState* PlayerState) const override;

private:
	bool bInnocentsWin;
};
