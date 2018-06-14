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

	UFUNCTION(Reliable, Client)
	void InitiatePlay();
	void InitiatePlay_Implementation();

	UFUNCTION(Reliable, Server, WithValidation)
	void InitiatePlayHelperServer(bool HMDEnabled, FVector HMDOffset, FRotator HMDRotation);
	void InitiatePlayHelperServer_Implementation(bool HMDEnabled, FVector HMDOffset, FRotator HMDRotation);
	bool InitiatePlayHelperServer_Validate(bool HMDEnabled, FVector HMDOffset, FRotator HMDRotation);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Initialization")
	TSubclassOf<class UPlayerWidget> PlayerWidgetTemplate;

	UPROPERTY()
	class UPlayerWidget* PlayerWidget;

	UPROPERTY(EditAnywhere, Category = "Initialization")
	TSubclassOf<class AABCharacter> FPSCharacterTemplate;

	UPROPERTY(EditAnywhere, Category = "Initialization")
	TSubclassOf<class AABCharacter> VRCharacterTemplate;

	void ServerSetTeam(ETeam Value);

	UFUNCTION(BlueprintPure, Category = "Team")
	ETeam GetTeam();

protected:
	
	UPROPERTY(Transient, ReplicatedUsing = OnRep_Team)
	ETeam Team;
};
