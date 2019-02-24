echo "Uploading dedicated & no-editor builds to Steamworks"

..\add-steam-client\add_steam_client.ps1

$GameBuildDir = (Get-Location).tostring() + "\upload-scripts-907100\app_build_player_vs.vdf"
$DedicatedBuildDir = (Get-Location).tostring() + "\upload-scripts-1023620\app_build_player_vs_dedicated.vdf"
$Credentials = .\steam_credentials.ps1

steamcmd +login $Credentials[0] $Credentials[1] +run_app_build $GameBuildDir +run_app_build $DedicatedBuildDir +quit