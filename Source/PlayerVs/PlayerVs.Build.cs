// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class PlayerVs : ModuleRules
{
	public PlayerVs(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "GameplayTags", "VRExpansionPlugin", "OnlineSubsystem", "OnlineSubsystemUtils", "Niagara" });

        DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");

        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore", "HeadMountedDisplay", "SteamVR" });
	}
}
