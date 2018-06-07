// Fill out your copyright notice in the Description page of Project Settings.

#include "Online/ABGameMode.h"
#include "Player/ABCharacter.h"
#include "Player/ABPlayerController.h"
#include "Player/ABPlayerState.h"
#include "Online/ABGameState.h"
//#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

AABGameMode::AABGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnOb(TEXT("/Game/Blueprints/Player/ABCharacter_BP"));
	DefaultPawnClass = PlayerPawnOb.Class;
	PlayerControllerClass = AABPlayerController::StaticClass();
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
	}
	else
	if (MyGameState->HasMatchStarted())
	{
		ErrorMessage = TEXT("Match has started.");
	}
	else
	{
		Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
	}
}

void AABGameMode::PostLogin(APlayerController * NewPlayer)
{
	Super::PostLogin(NewPlayer);

	//AABPlayerController* NewPC = Cast<AABPlayerController>(NewPlayer);
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
	UE_LOG(LogTemp, Warning, TEXT("Has match started %s"), *GetABGameState()->GetMatchState().ToString());
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
		auto PS = Cast<AABPlayerState>(UGameplayStatics::GetPlayerController(GetWorld(), AlienIndex)->PlayerState);
		if (PS->GetTeam() != ETeam::Alien)
		{
			PS->SetTeam(ETeam::Alien);
			AlienCount--;
		}
	}
}

void AABGameMode::UnassignedToInnocent()
{
	for (auto It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		auto PS = Cast<AABPlayerState>((*It)->PlayerState);
		if (PS->GetTeam() == ETeam::Unassigned)
		{
			PS->SetTeam(ETeam::Innocent);
		}
	}
}
