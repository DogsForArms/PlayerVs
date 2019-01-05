// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class PlayerVs : ModuleRules
{
	public PlayerVs(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "GameplayTags", "VRExpansionPlugin", "OnlineSubsystem", "OnlineSubsystemUtils" });

        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore", "HeadMountedDisplay", "SteamVR" });
        
		// Uncomment if you are using online features
		PrivateDependencyModuleNames.Add("OnlineSubsystem");

        DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
