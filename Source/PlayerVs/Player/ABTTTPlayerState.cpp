// Fill out your copyright notice in the Description page of Project Settings.

#include "ABTTTPlayerState.h"

void AABTTTPlayerState::Client_SetTeam_Implementation(ETeam Value)
{
	SetTeam(Value);
}

void AABTTTPlayerState::SetTeam(ETeam Value)
{
	Team = Value;
}

ETeam AABTTTPlayerState::GetTeam()
{
	return Team;
}