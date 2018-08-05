// Fill out your copyright notice in the Description page of Project Settings.

#include "ABGameState.h"
#include "Net/UnrealNetwork.h"

void AABGameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AABGameState, RemainingTime);
	DOREPLIFETIME(AABGameState, bTimerPaused);
}

void AABGameState::OnRep_MatchState()
{
	Super::OnRep_MatchState();
	UE_LOG(LogTemp, Warning, TEXT("ABGameState MathcState is %s"), *MatchState.ToString())
	OnMatchStateChanged.Broadcast(MatchState);
}