// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SteamHandler.generated.h"

UCLASS()
class ALIENBETRAYAL_API ASteamHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASteamHandler();

protected:

public:
    static FString GetSteamID(APlayerController* PC);
	
	
};
