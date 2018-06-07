// Fill out your copyright notice in the Description page of Project Settings.

#include "Net/UnrealNetwork.h"
#include "ABPlayerState.h"

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
	DOREPLIFETIME(AABPlayerState, Team);
}

void AABPlayerState::OnRep_Team()
{
	UE_LOG(LogTemp, Warning, TEXT("You have joined a team"))
}
