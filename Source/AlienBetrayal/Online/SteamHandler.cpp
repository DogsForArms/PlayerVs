// Fill out your copyright notice in the Description page of Project Settings.

#include "SteamHandler.h"
#include "Core.h"
#include "Online.h"
#include "Kismet/GameplayStatics.h"

ASteamHandler::ASteamHandler()
{
	PrimaryActorTick.bCanEverTick = false;

}

FString ASteamHandler::GetSteamID(APlayerController* PC)
{
    IOnlineSubsystem* ion = IOnlineSubsystem::Get();
    int32 ID = UGameplayStatics::GetPlayerControllerID(PC);
    TSharedPtr<const FUniqueNetId> pid = ion->GetIdentityInterface()->GetUniquePlayerId(ID);

    if (pid->IsValid()) {
        return pid->ToString();
    }
    return "Error";
}

FString ASteamHandler::GetOnlineServiceName()
{
    IOnlineSubsystem* ion = IOnlineSubsystem::Get();
    FText Name = ion->GetOnlineServiceName();
    return Name.ToString();
}

bool ASteamHandler::HasVoice()
{
    IOnlineSubsystem* ion = IOnlineSubsystem::Get();
    IOnlineVoicePtr Voice = ion->GetVoiceInterface();
    if (Voice.IsValid()) {
        return true;
    }
    return false;
}

