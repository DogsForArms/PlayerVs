// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GrippableStaticMeshActor.h"
#include "Types/Types.h"
#include "Magazine.generated.h"

/**
 * 
 */
class USphereComponent;

UCLASS()
class PLAYERVS_API AMagazine : public AGrippableStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMagazine(const FObjectInitializer& ObjectInitializer);


	EMagazineType GetAttachmentType() const;

	//UPROPERTY(VisibleDefaultsOnly)
	//USphereComponent* AttachmentPoint;


};
