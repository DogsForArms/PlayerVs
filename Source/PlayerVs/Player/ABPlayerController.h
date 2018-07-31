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
class PLAYERVS_API AABPlayerController : public AVRPlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

    void EnableVoice();
    void DisableVoice();

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_Team();

	UFUNCTION()
	void InitiatePlay();

	UFUNCTION()
	void InitiateHMD();

	UFUNCTION(Reliable, Server, WithValidation)
	void ServerSetHMDConfig(bool HMDEnabled, FVector HMDOffset, FRotator HMDRotation);

	UFUNCTION()
	void SetHMDConfig(bool HMDEnabled, FVector HMDOffset, FRotator HMDRotation);

public: 
	AABPlayerController();

	UPROPERTY()
	bool HMDEnable;

	UPROPERTY()
	FVector HMDOffset;
		
	UPROPERTY()
	FRotator HMDRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Initialization")
	TSubclassOf<class UPlayerWidget> PlayerWidgetTemplate;

	UPROPERTY()
	class UPlayerWidget* PlayerWidget;

	void ServerSetTeam(ETeam Value);

	UFUNCTION(BlueprintPure, Category = "Team")
	ETeam GetTeam();

protected:
	
	UPROPERTY(Transient, ReplicatedUsing = OnRep_Team)
	ETeam Team;
};
