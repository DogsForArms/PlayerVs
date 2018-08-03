// Fill out your copyright notice in the Description page of Project Settings.

#include "ABDeathMatchGameMode.h"
#include "Player/ABDeathMatchPlayerState.h"
#include "Player/ABPlayerController.h"

void AABDeathMatchGameMode::Killed(AController* Killer, AController* KilledPlayer, APawn* KilledPawn, const UDamageType* DamageType)
{
	AABPlayerController* KilledPC = Cast<AABPlayerController>(KilledPlayer);

	AABDeathMatchPlayerState* KillerPlayerState = Killer ? Cast<AABDeathMatchPlayerState>(Killer->PlayerState) : NULL;
	AABDeathMatchPlayerState* VictimPlayerState = KilledPlayer ? Cast<AABDeathMatchPlayerState>(KilledPlayer->PlayerState) : NULL;

	if (KillerPlayerState && KillerPlayerState != VictimPlayerState)
	{
		KillerPlayerState->ScoreKill(VictimPlayerState);
		//KillerPlayerState->InformAboutKill(KillerPlayerState, DamageType, VictimPlayerState);
	}

	if (VictimPlayerState)
	{
		VictimPlayerState->ScoreDeath(KillerPlayerState);
		//VictimPlayerState->BroadcastDeath(KillerPlayerState, DamageType, VictimPlayerState);
	}

	Super::Killed(Killer, KilledPlayer, KilledPawn, DamageType);
	if (KilledPC)
	{
		KilledPC->DelayedCharacterSpawn(5.0f);
	}
}


