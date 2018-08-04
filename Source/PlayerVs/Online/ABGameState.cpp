// Fill out your copyright notice in the Description page of Project Settings.

#include "ABGameState.h"
#include "Net/UnrealNetwork.h"

void AABGameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AABGameState, RemainingTime);
	DOREPLIFETIME(AABGameState, bTimerPaused);
}


