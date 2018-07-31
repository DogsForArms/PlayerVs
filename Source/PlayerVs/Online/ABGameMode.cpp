// Fill out your copyright notice in the Description page of Project Settings.

#include "Online/ABGameMode.h"
#include "Player/ABCharacter.h"
#include "Player/ABPlayerController.h"
#include "Player/ABPlayerState.h"
#include "Online/ABGameState.h"

AABGameMode::AABGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnOb(TEXT("/Game/Blueprints/Player/ABCharacter_BP"));
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerOb(TEXT("/Game/Blueprints/Player/ABPlayerController_BP"));
	//DefaultPawnClass = PlayerPawnOb.Class;
	PlayerControllerClass = PlayerControllerOb.Class;
	PlayerStateClass = AABPlayerState::StaticClass();
	GameStateClass = AABGameState::StaticClass();

	bUseSeamlessTravel = true;
}

// called before any gameplay begins
void AABGameMode::PreInitializeComponents()
{
	Super::PreInitializeComponents();

	GetWorldTimerManager().SetTimer(TimerHandle_DefaultTimer, this, &AABGameMode::DefaultTimer, GetWorldSettings()->GetEffectiveTimeDilation(), true);
}

void AABGameMode::PreLogin(const FString & Options, const FString & Address, const FUniqueNetIdRepl & UniqueId, FString & ErrorMessage)
{
	AABGameState* const MyGameState = GetABGameState();
	if (MyGameState->HasMatchEnded()) 
	{
		ErrorMessage = TEXT("Match has finished.");
		UE_LOG(LogTemp, Warning, TEXT("Player could not join %s"), *ErrorMessage)
	}
	else
	if (MyGameState->HasMatchStarted())
	{
		ErrorMessage = TEXT("Match has started.");
		UE_LOG(LogTemp, Warning, TEXT("Player could not join %s"), *ErrorMessage)
	}
	else
	{
		Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
	}
}

void AABGameMode::PostLogin(APlayerController * NewPlayer)
{
	Super::PostLogin(NewPlayer);

	AABPlayerController* NewPC = Cast<AABPlayerController>(NewPlayer);
	NewPC->InitiatePlay();
	//if (NewPC && NewPC->GetPawn() == NULL)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("NewPlayer joined and no pawn."))
	//}


}

void AABGameMode::HandleMatchIsWaitingToStart()
{
	Super::HandleMatchIsWaitingToStart();
}

void AABGameMode::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();

	AssignAliens(FMath::Max(1, NumPlayers / 3));
	UnassignedToInnocent();

}

bool AABGameMode::ReadyToStartMatch_Implementation()
{
	bool bIsReadyToStart = NumPlayers > 1;

	return bIsReadyToStart;
}

void AABGameMode::DefaultTimer()
{
//	UE_LOG(LogTemp, Warning, TEXT("Has match started %s"), *GetABGameState()->GetMatchState().ToString());
}

AABGameState* AABGameMode::GetABGameState()
{
	return Cast<AABGameState>(GameState);
}


void AABGameMode::AssignAliens(int AlienCount)
{
	while (AlienCount > 0)
	{
		int AlienIndex = FMath::RandRange(0, NumPlayers - 1);
		auto PS = Cast<AABPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), AlienIndex));
		if (PS->GetTeam() != ETeam::Alien)
		{
			PS->ServerSetTeam(ETeam::Alien);
			AlienCount--;
		}
	}
}

void AABGameMode::UnassignedToInnocent()
{
	for (auto It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		auto PS = Cast<AABPlayerController>((*It));
		if (PS->GetTeam() == ETeam::Unassigned)
		{
			PS->ServerSetTeam(ETeam::Innocent);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// Game Logic 

void AABGameMode::Killed(AController* Killer, AController* KilledPlayer, APawn* KilledPawn, const UDamageType* DamageType)
{
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
}
