// Fill out your copyright notice in the Description page of Project Settings.

#include "Online/ABGameMode.h"
#include "Online/ABGameState.h"
#include "Player/ABCharacter.h"
#include "Player/ABPlayerController.h"
#include "Player/ABPlayerState.h"
#include "GameFramework/PlayerStart.h"

AABGameMode::AABGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnOb(TEXT("/Game/Blueprints/Player/ABCharacter_BP"));
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerOb(TEXT("/Game/Blueprints/Player/ABPlayerController_BP"));

	static ConstructorHelpers::FClassFinder<APawn> CharacterOb(TEXT("/Game/Blueprints/Player/ABCharacter_BP"));
	static ConstructorHelpers::FClassFinder<APawn> FPSCharacterOb(TEXT("/Game/Blueprints/Player/FPS_ABCharacter_BP"));
	static ConstructorHelpers::FClassFinder<APawn> SpectatorOb(TEXT("/Game/Blueprints/Player/ABSpectator_BP"));

	PlayerControllerClass = PlayerControllerOb.Class;
	PlayerStateClass = AABPlayerState::StaticClass();
	GameStateClass = AABGameState::StaticClass();

	FPSCharacterTemplate = FPSCharacterOb.Class;
	VRCharacterTemplate = CharacterOb.Class;
	VRSpectatorTemplate = SpectatorOb.Class;

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

void AABGameMode::HandleMatchIsWaitingToStart()
{
	Super::HandleMatchIsWaitingToStart();

	auto GS = GetABGameState();
	if (GS) GS->RemainingTime = TimeBeforeMatch;
}

void AABGameMode::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();

	auto GS = GetABGameState();
	if (GS) GS->RemainingTime = RoundTime;
}

//NOT FOR OVERRIDES!
bool AABGameMode::ReadyToStartMatch_Implementation()
{
	return false;
}

void AABGameMode::DefaultTimer()
{
	AABGameState* GS = GetABGameState();
	if (!GS)
		return;
	UE_LOG(LogTemp, Warning, TEXT("DefaultTimer GetMatchState: %s (%d)"), *GetMatchState().ToString(), GS->RemainingTime)

	if (!GS->bTimerPaused && (IsMatchInProgress() || HasMatchEnded() || GameCanStartCountdown()))
	{
		GS->RemainingTime--;

		if (GS->RemainingTime <= 0)
		{
			if (GameCanStartCountdown())
			{
				StartMatch();
			}
			else
			if (IsMatchInProgress())
			{
				//Game ran out of time
				FinishMatch();
			}
			else
			if (HasMatchEnded())
			{
				UE_LOG(LogTemp, Warning, TEXT("DefaultTimer HasMatchEnded!"))
				RestartGame();
			}
		}
	}
}


//////////////////////////////////////////////////////////////////////////
// Game Logic 

void AABGameMode::ControllerNeedsCharacter(AController* Controller, bool HMDEnabled, FVector HMDOffset, FRotator HMDRotation)
{
	FTransform SpawnTransform;

	TArray<AActor*> Spawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), Spawns);
	if (!Spawns.Num())
	{
		UE_LOG(LogTemp, Error, TEXT("No PlayerStart found."))
	}
	else
	{
		int PlayerStartIndex = FMath::FRandRange(0, Spawns.Num() - 1);
		AActor *Spawn = Spawns[PlayerStartIndex];
		SpawnTransform = Spawn->GetActorTransform();
	}

	FActorSpawnParameters SpawnInfo;
	AABCharacter *Character;
	if (!HMDEnabled && FPSCharacterTemplate)
	{
		Character = GetWorld()->SpawnActor<AABCharacter>(FPSCharacterTemplate, SpawnTransform, SpawnInfo);
		UE_LOG(LogTemp, Warning, TEXT("Spawn FPSCharacterTemplate"))
	}
	else if (VRCharacterTemplate)
	{
		Character = GetWorld()->SpawnActor<AABCharacter>(VRCharacterTemplate, SpawnTransform, SpawnInfo);
		UE_LOG(LogTemp, Warning, TEXT("Spawn VRCharacterTemplate"))
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("FPS or VR Character templates are not set properly."))
			return;
	}

	Controller->Possess(Character);
}

void AABGameMode::ControllerNeedsSpectator(AController* Controller)
{
	AABPlayerController* KilledPC = Cast<AABPlayerController>(Controller);
	bool bHMDEnabled = KilledPC ? KilledPC->HMDEnable : false;

	FTransform SpawnTransform;
	if (Controller->GetPawn())
		SpawnTransform = Controller->GetPawn()->GetActorTransform();

	APawn* Spectator;
	FActorSpawnParameters SpawnInfo;
	if (VRSpectatorTemplate && bHMDEnabled)
	{
		Spectator = GetWorld()->SpawnActor<APawn>(VRSpectatorTemplate, SpawnTransform, SpawnInfo);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("FPS or VR Spectator templates are not set properly."))
		return;
	}

	Controller->Possess(Spectator);
}

//////////////////////////////////////////////////////////////////////////
// End Game logic Overrides

bool AABGameMode::GameCanStartCountdown()
{
	return NumPlayers >= MinimumPlayers && MatchState::WaitingToStart == GetMatchState();
}

void AABGameMode::Killed(AController* Killer, AController* KilledPlayer, APawn* KilledPawn, const UDamageType* DamageType)
{
	ControllerNeedsSpectator(KilledPlayer);
}

float AABGameMode::ModifyDamage(float Damage, AActor* DamagedActor, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) const
{
	return IsMatchInProgress() ? Damage : 0.f;
}

void AABGameMode::DetermineMatchWinner()
{
	// nothing to do here
}

bool AABGameMode::IsWinner(AABPlayerState* PlayerState) const
{
	return false;
}

//////////////////////////////////////////////////////////////////////////
// Hyelpers

AABGameState* AABGameMode::GetABGameState()
{
	return Cast<AABGameState>(GameState);
}

void AABGameMode::FinishMatch()
{
	AABGameState* const GS = Cast<AABGameState>(GameState);
	if (IsMatchInProgress() && GS)
	{
		EndMatch();
		DetermineMatchWinner();

		for (FConstControllerIterator It = GetWorld()->GetControllerIterator(); It; ++It)
		{
			AABPlayerState* PlayerState = Cast<AABPlayerState>((*It)->PlayerState);
			const bool bIsWinner = IsWinner(PlayerState);
			(*It)->GameHasEnded(NULL, bIsWinner);
		}

		GS->RemainingTime = TimeBetweenMatches;
	}
}