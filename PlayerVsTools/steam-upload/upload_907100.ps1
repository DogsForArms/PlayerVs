echo "Uploading no-editor build to Steamworks"

$GameBuildDir = (Get-Location).tostring() + "\upload-scripts-907100\app_build_player_vs.vdf"
$Credentials = .\steam_credentials.ps1

steamcmd +login $Credentials[0] $Credentials[1] +run_app_build $GameBuildDir +quit