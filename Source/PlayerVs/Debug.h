// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Debug.generated.h"


UCLASS()
class PLAYERVS_API UDebug : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:

	static FORCEINLINE FString BoolToString(bool b)
	{
		return b ? FString("yes") : FString("no");
	}

	static FORCEINLINE FString NameOrNull(const UObject* O)
	{
		return O ? O->GetName() : FString("NULL");
	}

	static FORCEINLINE FString GetNetModeName(ENetMode NetMode)
	{
		switch (NetMode)
		{
		case ENetMode::NM_Client: return FString("NM_Client");
		case ENetMode::NM_DedicatedServer: return FString("NM_DedicatedServer");
		case ENetMode::NM_ListenServer: return FString("NM_ListenServer");
		case ENetMode::NM_MAX: return FString("NM_MAX");
		case ENetMode::NM_Standalone: return FString("NM_Standalone");
		}

		return FString("Unknown");
	}

	static FORCEINLINE FString GetNetRoleName(ENetRole NetRole)
	{
		switch (NetRole)
		{
		case ENetRole::ROLE_None: return FString("ROLE_None");
		case ENetRole::ROLE_SimulatedProxy: return FString("ROLE_SimulatedProxy");
		case ENetRole::ROLE_AutonomousProxy: return FString("ROLE_AutonomousProxy");
		case ENetRole::ROLE_Authority: return FString("ROLE_Authority");
		case ENetRole::ROLE_MAX: return FString("ROLE_MAX");
		}

		return FString("Unknown");
	}

	static FORCEINLINE FString ActorDebugNet(AActor* Actor)
	{
		if (Actor) {
			FString name = Actor->GetName();
			FString NetMode = GetNetModeName(Actor->GetNetMode());
			FString LocalNetRole = GetNetRoleName(Actor->GetLocalRole());
			FString RemoteNetRole = GetNetRoleName(Actor->GetRemoteRole());
			FString HasAuthority = Actor->HasAuthority() ? FString("yes") : FString("no");
			FString OwnerName = NameOrNull(Actor->GetOwner());

			return FString::Printf(TEXT("[(%s)\M: %s\tLR: %s\tRR: %s\tAuth: %s\tOwner: %s]"), *name, *NetMode, *LocalNetRole, *RemoteNetRole, *HasAuthority, *OwnerName);
		}

		return FString("[NULL]");
	}

	static FORCEINLINE FString ActorNetRole(AActor* Actor)
	{
		if (Actor) {
			FString name = Actor->GetName();
			FString LocalNetRole = GetNetRoleName(Actor->GetLocalRole());
			FString RemoteNetRole = GetNetRoleName(Actor->GetRemoteRole());
			FString HasAuthority = Actor->HasAuthority() ? FString("yes") : FString("no");
			FString OwnerName = NameOrNull(Actor->GetOwner());

			return FString::Printf(TEXT("[(%s)\tLR\t%s\tRR: %s\tAuth: %s\tOwner: %s]"), *name, *LocalNetRole, *RemoteNetRole, *HasAuthority, *OwnerName);
		}

		return FString("[NULL]");
	}
};