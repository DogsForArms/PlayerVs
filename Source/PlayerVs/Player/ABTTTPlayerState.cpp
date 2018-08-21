// Fill out your copyright notice in the Description page of Project Settings.

#include "ABTTTPlayerState.h"
#include "Net/UnrealNetwork.h"

AABTTTPlayerState::AABTTTPlayerState() { }

void AABTTTPlayerState::Client_SetTeam_Implementation(ETeam Value)
{
	SetTeam(Value);
}

void AABTTTPlayerState::Client_SetTraitors_Implementation(const TArray<AABTTTPlayerState*>& Traitors)
{
	for (AABTTTPlayerState* Traitor : Traitors)
	{
		this->Traitors.Add(Traitor);
	}
}

void AABTTTPlayerState::RevealAll()
{
	All_Client_SetAll(Team, InnocentsKilled, TraitorsKilled, bIsAlive);
}

void AABTTTPlayerState::All_Client_SetAll_Implementation(ETeam Team, int32 InnocentsKilled, int32 TraitorsKilled, bool bIsAlive)
{
	this->Team = Team;
	this->InnocentsKilled = InnocentsKilled;
	this->TraitorsKilled = TraitorsKilled;
	this->bIsAlive = bIsAlive;
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

void AABTTTPlayerState::IncrementInnocentsKilled()
{
	InnocentsKilled++;
}
void AABTTTPlayerState::IncrementTraitorsKilled()
{
	TraitorsKilled++;
}

int32 AABTTTPlayerState::GetInnocentsKilled() const
{
	return InnocentsKilled;
}

int32 AABTTTPlayerState::GetTraitorsKilled() const
{
	return TraitorsKilled;
}