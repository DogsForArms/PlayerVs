// Fill out your copyright notice in the Description page of Project Settings.

#include "ABDeathMatchPlayerState.h"

void AABDeathMatchPlayerState::ScoreKill(AABDeathMatchPlayerState* Victim)
{
	NumKills++;
}

void AABDeathMatchPlayerState::ScoreDeath(AABDeathMatchPlayerState* KilledBy)
{
	NumDeaths++;
}