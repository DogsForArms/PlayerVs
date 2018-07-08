// Fill out your copyright notice in the Description page of Project Settings.

#include "SteamHandler.h"
#include "CoreMinimal.h"
#include "Online.h"

ASteamHandler::ASteamHandler()
{
	PrimaryActorTick.bCanEverTick = false;

}

FString ASteamHandler::GetSteamID(APlayerController* PC)
{

    ULocalPlayer* LP = Cast<ULocalPlayer>(PC->Player);
    if (LP)
    {
        int32 ID = LP->GetControllerId();
        IOnlineSubsystem* ion = IOnlineSubsystem::Get();
        TSharedPtr<const FUniqueNetId> pid = ion->GetIdentityInterface()->GetUniquePlayerId(ID);
        if (pid->IsValid())
        {
            return pid->ToString();
        } else
        {
            UE_LOG(LogTemp, Error, TEXT("SteamHandler GetSteamID Error: pid is invalid"))
        }
    } else
    {
        UE_LOG(LogTemp, Error, TEXT("SteamHandler GetSteamID Error: PC->Player is not LocalPlayer"))
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
    IOnlineVoicePtr VoiceInt = ion->GetVoiceInterface();
    if (VoiceInt.IsValid()) {
        return true;
    }
    return false;
}

bool ASteamHandler::ToggleSpeaking(APlayerController* PC, bool bSpeaking)
{
    ULocalPlayer* LP = Cast<ULocalPlayer>(PC->Player);
    if (LP != NULL)
    {
        IOnlineSubsystem* ion = IOnlineSubsystem::Get();
        IOnlineVoicePtr VoiceInt = ion->GetVoiceInterface();
        if (VoiceInt.IsValid())
        {
            if (bSpeaking)
            {
                VoiceInt->StartNetworkedVoice(LP->GetControllerId());
            }
            else
            {
                VoiceInt->StopNetworkedVoice(LP->GetControllerId());
            }
            return true;
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("ToggleSpeaking failed:  VoiceInterface is not valid for service name %s"), *ASteamHandler::GetOnlineServiceName())
        }
    } else
    {
        UE_LOG(LogTemp, Error, TEXT("ToggleSpeaking failed:  PC->Player is not LocalPlayer."))
    }
    return false;
}

