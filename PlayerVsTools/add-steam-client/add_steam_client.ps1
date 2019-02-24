$SteamClientBinariesRoot = 'A:\UE4\projects\PlayerVs\PlayerVsTools\add-steam-client'
$StagedBuildsRoot = 'A:\UE4\projects\PlayerVs\Saved\StagedBuilds'

Copy-Item ($SteamClientBinariesRoot + '\linux64-binaries\*') -Destination ($StagedBuildsRoot + '\LinuxServer\PlayerVs\Binaries\Linux')
Copy-Item ($SteamClientBinariesRoot + '\windows64-binaries\*') -Destination ($StagedBuildsRoot + '\WindowsServer\PlayerVs\Binaries\Win64')