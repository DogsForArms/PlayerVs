// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Types.h"
#include "ABPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ALIENBETRAYAL_API AABPlayerState : public APlayerState
{
	GENERATED_BODY()

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const override;

	/** replicate team.  TODO Updated the players hud*/
	UFUNCTION()
	void OnRep_Team();

public:

	void SetTeam(ETeam Value);
	ETeam GetTeam();

protected:
	UPROPERTY(Transient, ReplicatedUsing = OnRep_Team)
	ETeam Team;
	
};
