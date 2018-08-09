// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class PlayerVsServerTarget : TargetRules
{
	public PlayerVsServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
        bUsesSteam = true;
		ExtraModuleNames.AddRange( new string[] { "PlayerVs" } );
	}
}
