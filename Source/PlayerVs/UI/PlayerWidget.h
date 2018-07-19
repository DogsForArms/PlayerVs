// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Player/Types.h"
#include "PlayerWidget.generated.h"


/**
 * 
 */
UCLASS()
class PLAYERVS_API UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintImplementableEvent, Category = "MyEvents")
	void OnChangeTeam(ETeam Value);

};
