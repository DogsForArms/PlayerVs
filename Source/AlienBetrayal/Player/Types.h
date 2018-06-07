// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

UENUM(BlueprintType)
enum class ETeam : uint8
{
	Unassigned		UMETA(DisplayName = "Unassigned"),
	Alien			UMETA(DisplayName = "Alien"),
	Innocent		UMETA(DisplayName = "Innocent")
};