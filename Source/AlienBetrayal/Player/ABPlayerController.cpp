// Fill out your copyright notice in the Description page of Project Settings.

#include "ABPlayerController.h"
#include "Net/UnrealNetwork.h"
#include "Engine.h"
#include "Blueprint/UserWidget.h"
#include "UI/PlayerWidget.h"

AABPlayerController::AABPlayerController()
{

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
	if (PlayerWidgetTemplate)
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
}

void AABPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//InputComponent->BindAction("Esc", IE_Pressed, this, &AOrthoPlayerController::ToggleGameMenu);
}