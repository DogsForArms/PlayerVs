// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Online/ABGameMode.h"
#include "ABDeathMatchGameMode.generated.h"

class AABDeathMatchPlayerState;
/**
 * 
 */
UCLASS()
class PLAYERVS_API AABDeathMatchGameMode : public AABGameMode
{
	GENERATED_UCLASS_BODY()
	
public:
	virtual void PostInitProperties() override;

	virtual void Killed(AController* Killer, AController* KilledPlayer, APawn* KilledPawn, const UDamageType* DamageType) override;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "config")
	int32 MaxKills;

	void DetermineMatchWinner() override;
	bool IsWinner(AABPlayerState* PlayerState) const override;

	UPROPERTY()
	AABDeathMatchPlayerState* Winner;	
};
