// Fill out your copyright notice in the Description page of Project Settings.

#include "ABDeathMatchPlayerState.h"
#include "Net/UnrealNetwork.h"

void AABDeathMatchPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AABDeathMatchPlayerState, NumKills);
	DOREPLIFETIME(AABDeathMatchPlayerState, NumDeaths);
}

void AABDeathMatchPlayerState::ScoreKill(AABDeathMatchPlayerState* Victim)
{
	NumKills++;
}

void AABDeathMatchPlayerState::ScoreDeath(AABDeathMatchPlayerState* KilledBy)
{
	NumDeaths++;
}

int AABDeathMatchPlayerState::GetNumKills()
{
	return NumKills;
}

int AABDeathMatchPlayerState::GetNumDeaths()
{
	return NumDeaths;
}