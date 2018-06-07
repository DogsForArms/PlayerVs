// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine.h"
#include "ABPlayerState.h"
#include "Net/UnrealNetwork.h"

void AABPlayerState::SetTeam(ETeam Value)
{
	Team = Value;
}

ETeam AABPlayerState::GetTeam()
{
	return Team;
}

/**
	OnRep functions
*/

void AABPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AABPlayerState, Team, COND_OwnerOnly);
}

void AABPlayerState::OnRep_Team()
{
	if (Team == ETeam::Alien)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("You're an Alien"));
	} else
	if (Team == ETeam::Innocent)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("You're an Innocent"));
	}
}
