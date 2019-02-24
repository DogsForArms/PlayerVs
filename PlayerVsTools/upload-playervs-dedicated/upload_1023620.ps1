echo "Uploading dedicated builds to Steamworks"

..\add-steam-client\add_steam_client.ps1

$DedicatedBuildDir = (Get-Location).tostring() + "\upload-scripts-1023620\app_build_player_vs_dedicated.vdf"
$Credentials = .\steam_credentials.ps1

steamcmd +login $Credentials[0] $Credentials[1] +run_app_build $DedicatedBuildDir +quit