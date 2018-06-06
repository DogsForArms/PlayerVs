// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRPlayerController.h"
#include "ABPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ALIENBETRAYAL_API AABPlayerController : public AVRPlayerController
{
	GENERATED_BODY()

public: 
	AABPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
};
