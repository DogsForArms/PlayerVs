// Fill out your copyright notice in the Description page of Project Settings.

#include "ABPlayerController.h"
#include "Net/UnrealNetwork.h"

AABPlayerController::AABPlayerController()
{

}

void AABPlayerController::BeginPlay()
{

}

void AABPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//InputComponent->BindAction("Esc", IE_Pressed, this, &AOrthoPlayerController::ToggleGameMenu);
}