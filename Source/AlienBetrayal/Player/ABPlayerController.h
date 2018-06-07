// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRPlayerController.h"
#include "Types.h"
#include "ABPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ALIENBETRAYAL_API AABPlayerController : public AVRPlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const override;

	/** replicate team.  TODO Updated the players hud*/
	UFUNCTION()
	void OnRep_Team();

public: 
	AABPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UPlayerWidget> PlayerWidgetTemplate;

	class UPlayerWidget* PlayerWidget;

	void ServerSetTeam(ETeam Value);

	UFUNCTION(BlueprintPure, Category = "Team")
	ETeam GetTeam();

protected:
	
	UPROPERTY(Transient, ReplicatedUsing = OnRep_Team)
	ETeam Team;
};
