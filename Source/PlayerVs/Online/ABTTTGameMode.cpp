// Fill out your copyright notice in the Description page of Project Settings.

#include "ABTTTGameMode.h"
#include "Player/ABTTTPlayerState.h"
#include "Player/Types.h"
#include "Kismet/GameplayStatics.h"

AABTTTGameMode::AABTTTGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PlayerStateClass = AABTTTPlayerState::StaticClass();
}

void AABTTTGameMode::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();

	AssignAliens(FMath::Max(1, NumPlayers / 3));
	UnassignedToInnocent();
}

void AABTTTGameMode::Killed(AController* Killer, AController* KilledPlayer, APawn* KilledPawn, const UDamageType* DamageType)
{
	Super::Killed(Killer, KilledPlayer, KilledPawn, DamageType);
}

void AABTTTGameMode::AssignAliens(int AlienCount)
{
	while (AlienCount > 0)
	{
		int AlienIndex = FMath::RandRange(0, NumPlayers - 1);
		auto PlayerState = Cast<AABTTTPlayerState>(UGameplayStatics::GetPlayerController(GetWorld(), AlienIndex)->PlayerState);
		if (PlayerState->GetTeam() != ETeam::Alien)
		{
			PlayerState->SetTeam(ETeam::Alien);
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
		}
	}
}


