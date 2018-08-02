// Fill out your copyright notice in the Description page of Project Settings.

#include "ABDeathMatchGameMode.h"
#include "Player/ABPlayerState.h"
#include "Player/ABPlayerController.h"

void AABDeathMatchGameMode::Killed(AController* Killer, AController* KilledPlayer, APawn* KilledPawn, const UDamageType* DamageType)
{
	AABPlayerController* KilledPC = Cast<AABPlayerController>(KilledPlayer);

	AABPlayerState* KillerPlayerState = Killer ? Cast<AABPlayerState>(Killer->PlayerState) : NULL;
	AABPlayerState* VictimPlayerState = KilledPlayer ? Cast<AABPlayerState>(KilledPlayer->PlayerState) : NULL;

	if (KillerPlayerState && KillerPlayerState != VictimPlayerState)
	{
		//KillerPlayerState->ScoreKill(VictimPlayerState, KillScore);
		//KillerPlayerState->InformAboutKill(KillerPlayerState, DamageType, VictimPlayerState);
	}

	if (VictimPlayerState)
	{
		//VictimPlayerState->ScoreDeath(KillerPlayerState, DeathScore);
		//VictimPlayerState->BroadcastDeath(KillerPlayerState, DamageType, VictimPlayerState);
	}

	Super::Killed(Killer, KilledPlayer, KilledPawn, DamageType);
}


