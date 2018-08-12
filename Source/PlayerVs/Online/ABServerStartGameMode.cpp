// Fill out your copyright notice in the Description page of Project Settings.

#include "ABServerStartGameMode.h"
#include "Types/Types.h"

//https://answers.unrealengine.com/questions/123559/can-we-make-command-line-arguments.html
/*
//mygame.exe -skinByClass -startPose 2 -scb="\pathtoafile"
if (FParse::Value(FCommandLine::Get(), TEXT("scb"), fileName)) {
	fileName = fileName.Replace(TEXT("="), TEXT("")).Replace(TEXT("\""), TEXT("")); // replace quotes
	_SCBFile = fileName;
}
*/
FGameConfig AABServerStartGameMode::ParseGameConfigFromCommandLine() const
{
	FGameConfig GameConfig;

	FParse::Value(FCommandLine::Get(), *GameConfigKeys::ServerNameKey, GameConfig.ServerName);
	FParse::Value(FCommandLine::Get(), *GameConfigKeys::GameKey, GameConfig.Game);
	FParse::Value(FCommandLine::Get(), *GameConfigKeys::MapKey, GameConfig.Map);

	return GameConfig;
}

