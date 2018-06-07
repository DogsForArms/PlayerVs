// Fill out your copyright notice in the Description page of Project Settings.

#include "ABPlayerController.h"
#include "Net/UnrealNetwork.h"
#include "Engine.h"

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
	if (Team == ETeam::Alien)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("You're an Alien"));
	}
	else
	if (Team == ETeam::Innocent)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("You're an Innocent"));
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

}

void AABPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//InputComponent->BindAction("Esc", IE_Pressed, this, &AOrthoPlayerController::ToggleGameMenu);
}