// Fill out your copyright notice in the Description page of Project Settings.

#include "DedicatedGameMode.h"

//https://answers.unrealengine.com/questions/123559/can-we-make-command-line-arguments.html
/*
//mygame.exe -skinByClass -startPose 2 -scb="\pathtoafile"
if (FParse::Value(FCommandLine::Get(), TEXT("scb"), fileName)) {
	fileName = fileName.Replace(TEXT("="), TEXT("")).Replace(TEXT("\""), TEXT("")); // replace quotes
	_SCBFile = fileName;
}
*/
FGameConfig ADedicatedGameMode::ParseGameConfigFromCommandLine() const
{
	FGameConfig GameConfig;

	GameConfig.ServerName = ServerName;
	GameConfig.Map = Map;
	GameConfig.Game = Game;
	GameConfig.RoundTime = RoundTime;
	GameConfig.MinimumPlayers = MinimumPlayers;
	GameConfig.MaximumPlayers = MaximumPlayers;
	GameConfig.TimeBetweenMatches = TimeBetweenMatches;
	GameConfig.TimeBeforeMatch = TimeBeforeMatch;

	FParse::Value(FCommandLine::Get(), *GameConfigKeys::ServerNameKey, GameConfig.ServerName);
	FParse::Value(FCommandLine::Get(), *GameConfigKeys::GameKey, GameConfig.Game);
	FParse::Value(FCommandLine::Get(), *GameConfigKeys::MapKey, GameConfig.Map);

	FParse::Value(FCommandLine::Get(), *GameConfigKeys::RoundTimeKey, GameConfig.RoundTime);
	FParse::Value(FCommandLine::Get(), *GameConfigKeys::MinimumPlayersKey, GameConfig.MinimumPlayers);
	FParse::Value(FCommandLine::Get(), *GameConfigKeys::MaximumPlayersKey, GameConfig.MaximumPlayers);
	FParse::Value(FCommandLine::Get(), *GameConfigKeys::TimeBetweenMatchesKey, GameConfig.TimeBetweenMatches);
	FParse::Value(FCommandLine::Get(), *GameConfigKeys::TimeBeforeMatchKey, GameConfig.TimeBeforeMatch);

	return GameConfig;
}



