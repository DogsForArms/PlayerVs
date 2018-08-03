// Fill out your copyright notice in the Description page of Project Settings.

#include "ABPlayerController.h"
#include "Net/UnrealNetwork.h"
#include "Engine.h"
#include "UI/PlayerWidget.h"
#include "Online/SteamHandler.h"
#include "Online/ABGameMode.h"

AABPlayerController::AABPlayerController()
{

}

void AABPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AABPlayerController, Team, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(AABPlayerController, bIsWaitingForRespawn, COND_OwnerOnly);
    DOREPLIFETIME_CONDITION(AABPlayerController, RespawnCountdown, COND_OwnerOnly);
}

void AABPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("PushToTalk", IE_Pressed, this, &AABPlayerController::EnableVoice);
	InputComponent->BindAction("PushToTalk", IE_Released, this, &AABPlayerController::DisableVoice);
}

void AABPlayerController::OnRep_Team()
{
	if (PlayerWidget)
	{
		PlayerWidget->OnChangeTeam(Team);
	}
}

void AABPlayerController::ServerSetTeam(ETeam Value)
{
	if (HasAuthority()) 
	{
		Team = Value;
	}
}

ETeam AABPlayerController::GetTeam()
{
	return Team;
}

void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (IsLocalPlayerController())
	{
		if (PlayerWidgetTemplate)
		{
			PlayerWidget = CreateWidget<UPlayerWidget>(this, PlayerWidgetTemplate);
			if (PlayerWidget)
			{
				PlayerWidget->AddToViewport();
			}
			//Widget can be created after OnRep_Team event, then your team will not be displayed. :[
			OnRep_Team();
		}

		InitiatePlay();
	}

    //UE_LOG(LogTemp, Warning, TEXT("DebugSteam: GetSteamID : %s"), *ASteamHandler::GetSteamID(this))
    //UE_LOG(LogTemp, Warning, TEXT("DebugSteam: OnlineServiceName : %s"), *ASteamHandler::GetOnlineServiceName())
    //UE_LOG(LogTemp, Warning, TEXT("DebugSteam: HasVoice : %d"), ASteamHandler::HasVoice())
}

void AABPlayerController::InitiatePlay()
{
	bool HMDEnabled = UVRExpansionFunctionLibrary::GetIsHMDConnected() && UVRExpansionFunctionLibrary::IsInVREditorPreviewOrGame();
	FVector HMDOffset;
	FRotator HMDOrientation;
	//https://answers.unrealengine.com/questions/207990/link-error-unresolved-getpositionaltrackingcamerap.html
	//UHeadMountedDisplayFunctionLibrary::GetOrientationAndPosition(HMDOrientation, HMDOffset);

	InitiateHMD();
	ServerSetHMDConfig(HMDEnabled, HMDOffset, HMDOrientation);
}

void AABPlayerController::InitiateHMD()
{
	FString Commands[] = {
		TEXT("vr.bEnableStereo 1"),
		TEXT("r.setres 1280x720"),
		TEXT("sg.ResolutionQuality 100"),
		// reduce TAA blur
		TEXT("r.temporalAAsamples 1"),
		TEXT("r.temporalAAsharpness 1")
	};

	for (const FString &Cmd : Commands)
		ConsoleCommand(Cmd, true);
}

void AABPlayerController::SetHMDConfig(bool HMDEnabled, FVector HMDOffset, FRotator HMDRotation)
{
	this->HMDEnable = HMDEnabled;
	this->HMDOffset = HMDOffset;
	this->HMDRotation = HMDRotation;
}

void AABPlayerController::ServerSetHMDConfig_Implementation(bool HMDEnabled, FVector HMDOffset, FRotator HMDRotation)
{
	SetHMDConfig(HMDEnabled, HMDOffset, HMDRotation);

	//GameMode will now spawn based on HMDEnabled
	GetWorld()->GetAuthGameMode<AABGameMode>()->ControllerNeedsCharacter(this, HMDEnabled, HMDOffset, HMDRotation);
}

bool AABPlayerController::ServerSetHMDConfig_Validate(bool HMDEnabled, FVector HMDOffset, FRotator HMDRotation)
{
	return true;
}

void AABPlayerController::EnableVoice()
{
    StartTalking();
}

void AABPlayerController::DisableVoice()
{
    StopTalking();
}

void AABPlayerController::DelayedCharacterSpawn(float Delay)
{
    bIsWaitingForRespawn = true;
    RespawnAfterTimeSeconds = GetWorld()->GetTimeSeconds() + Delay;
    RespawnCountdown = Delay;
    GetWorld()->GetTimerManager().SetTimer(RespawnTimer, this, &AABPlayerController::TryRespawn, 1, true);
}

void AABPlayerController::TryRespawn()
{
    RespawnCountdown = RespawnAfterTimeSeconds - GetWorld()->GetTimeSeconds();
    if (RespawnCountdown <= 0)
    {
        RespawnCountdown = 0;
        GetWorld()->GetTimerManager().ClearTimer(RespawnTimer);
		GetWorld()->GetAuthGameMode<AABGameMode>()->ControllerNeedsCharacter(this, this->HMDEnable, this->HMDOffset, this->HMDRotation);
    }
}

