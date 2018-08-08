// Fill out your copyright notice in the Description page of Project Settings.

#include "ABTTTGameMode.h"
#include "Online/ABTTTGameState.h"
#include "Player/ABTTTPlayerState.h"
#include "Types/Types.h"
#include "Kismet/GameplayStatics.h"

AABTTTGameMode::AABTTTGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GameStateClass = AABTTTGameState::StaticClass();
	PlayerStateClass = AABTTTPlayerState::StaticClass();
}

void AABTTTGameMode::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();

	AssignAliens(FMath::Max(1, NumPlayers / 3));
	UnassignedToInnocent();
}

void AABTTTGameMode::HandleMatchHasEnded()
{
	Super::HandleMatchHasEnded();
	for (auto It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		auto PS = Cast<AABTTTPlayerState>((*It)->PlayerState);
		PS->All_Client_SetTeam(PS->GetTeam());		
	}
}

void AABTTTGameMode::Killed(AController* Killer, AController* KilledPlayer, APawn* KilledPawn, const UDamageType* DamageType)
{
	Super::Killed(Killer, KilledPlayer, KilledPawn, DamageType);
	auto PS = Cast<AABTTTPlayerState>(KilledPlayer->PlayerState);
	if (PS)
	{
		PS->SetIsAlive(false);
	}
}

void AABTTTGameMode::AssignAliens(int AlienCount)
{
	check(AlienCount <= NumPlayers);

	while (AlienCount > 0)
	{
		int AlienIndex = FMath::RandRange(0, NumPlayers - 1);
		auto PS = Cast<AABTTTPlayerState>(UGameplayStatics::GetPlayerController(GetWorld(), AlienIndex)->PlayerState);
		if (PS->GetTeam() != ETeam::Alien)
		{
			PS->SetTeam(ETeam::Alien);
			PS->Client_SetTeam(ETeam::Alien);
			AlienCount--;
		}
	}
}

void AABTTTGameMode::UnassignedToInnocent()
{
	for (auto It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		auto PS = Cast<AABTTTPlayerState>((*It)->PlayerState);
		if (PS->GetTeam() == ETeam::Unassigned)
		{
			PS->SetTeam(ETeam::Innocent);
			PS->Client_SetTeam(ETeam::Innocent);
		}
	}
}

bool AABTTTGameMode::GameCanStartCountdown()
{
	return true && Super::GameCanStartCountdown();
}

void AABTTTGameMode::DetermineMatchWinner()
{
	int NumInnocent = 0;

	for (auto It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		auto PS = Cast<AABTTTPlayerState>((*It)->PlayerState);
		if (PS && PS->GetIsAlive() && PS->GetTeam() != ETeam::Alien)
		{
			NumInnocent++;
		}
	}

	bInnocentsWin = NumInnocent > 0;
}

bool AABTTTGameMode::IsWinner(AABPlayerState* PlayerState) const
{
	auto PS = Cast<AABTTTPlayerState>(PlayerState);
	return PS && (
		(PS->GetTeam() == ETeam::Innocent && bInnocentsWin) ||
		(PS->GetTeam() != ETeam::Innocent && !bInnocentsWin)
	);
}