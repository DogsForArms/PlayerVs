// Fill out your copyright notice in the Description page of Project Settings.

#include "ABPlayerController.h"
#include "Net/UnrealNetwork.h"
#include "Engine.h"
#include "UI/PlayerWidget.h"
#include "ABCharacter.h"
#include "Online/SteamHandler.h"

AABPlayerController::AABPlayerController()
{

}

void AABPlayerController::InitiatePlay_Implementation()
{
	bool HMDEnabled = UVRExpansionFunctionLibrary::GetIsHMDConnected() && UVRExpansionFunctionLibrary::IsInVREditorPreviewOrGame();
	FVector HMDOffset;
	FRotator HMDOrientation;
	//https://answers.unrealengine.com/questions/207990/link-error-unresolved-getpositionaltrackingcamerap.html
	//UHeadMountedDisplayFunctionLibrary::GetOrientationAndPosition(HMDOrientation, HMDOffset);
	
	InitiatePlayHelperServer(HMDEnabled, HMDOffset, HMDOrientation);
}

void AABPlayerController::InitiateHMD()
{
	FString Commands[] = { 
		TEXT("vr.bEnableStereo 1"), 
		TEXT("r.setres 1280x720"),
		TEXT("sg.ResolutionQuality 100" ),
		TEXT("r.temporalAAsamples 1"),
		TEXT("r.temporalAAsharpness 1")
	};

	for (const FString &Cmd : Commands)
		ConsoleCommand(Cmd, true);
}

void AABPlayerController::InitiatePlayHelperServer_Implementation(bool HMDEnabled, FVector HMDOffset, FRotator HMDRotation)
{
	FTransform SpawnTransform;

	TArray<AActor*> Spawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), Spawns);
	if (!Spawns.Num()) 
	{
		UE_LOG(LogTemp, Error, TEXT("No PlayerStart found."))
	} else
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

	Possess(Character);
	InitiateHMD();
}

bool AABPlayerController::InitiatePlayHelperServer_Validate(bool HMDEnabled, FVector HMDOffset, FRotator HMDRotation)
{
	return true;
}

void AABPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AABPlayerController, Team, COND_OwnerOnly);
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
	if (PlayerWidgetTemplate && IsLocalPlayerController())
	{
		PlayerWidget = CreateWidget<UPlayerWidget>(this, PlayerWidgetTemplate);
		if (PlayerWidget)
		{
			PlayerWidget->AddToViewport();
		}
		//Widget can be created after OnRep_Team event, then your team will not be displayed. :[
		OnRep_Team();
	}

    //UE_LOG(LogTemp, Warning, TEXT("DebugSteam: GetSteamID : %s"), *ASteamHandler::GetSteamID(this))
    //UE_LOG(LogTemp, Warning, TEXT("DebugSteam: OnlineServiceName : %s"), *ASteamHandler::GetOnlineServiceName())
    //UE_LOG(LogTemp, Warning, TEXT("DebugSteam: HasVoice : %d"), ASteamHandler::HasVoice())
}

void AABPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
    InputComponent->BindAction("PushToTalk", IE_Pressed, this, &AABPlayerController::EnableVoice);
    InputComponent->BindAction("PushToTalk", IE_Released, this, &AABPlayerController::DisableVoice);
}

void AABPlayerController::EnableVoice()
{
    StartTalking();
}

void AABPlayerController::DisableVoice()
{
    StopTalking();
}
