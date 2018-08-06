// Fill out your copyright notice in the Description page of Project Settings.

#include "ABTTTPlayerState.h"
#include "Net/UnrealNetwork.h"

AABTTTPlayerState::AABTTTPlayerState()
{
	Team = ETeam::Unassigned;
}

void AABTTTPlayerState::Client_SetTeam_Implementation(ETeam Value)
{
	SetTeam(Value);
}

void AABTTTPlayerState::All_Client_SetTeam_Implementation(ETeam Value)
{
	SetTeam(Value);
}

void AABTTTPlayerState::SetTeam(ETeam Value)
{
	Team = Value;
}

ETeam AABTTTPlayerState::GetTeam() const
{
	return Team;
}

bool AABTTTPlayerState::GetIsAlive() const
{
	return bIsAlive;
}

void AABTTTPlayerState::SetIsAlive(bool Value)
{
	bIsAlive = Value;
}