
$Force = $arg
$CredentialsFile = '.\credentials.txt'

# User inputs credentials & Save
if (-NOT (Test-Path $CredentialsFile)) 
{
	$UsernameInput = Read-Host 'What is your steam username?'
	$PasswordInput = Read-Host 'What is your steam password?' -AsSecureString
	$PasswordInputSecure = ConvertFrom-SecureString -SecureString $PasswordInput

	"$UsernameInput,$PasswordInputSecure" > $CredentialsFile
}

# read creds from file
$Credentials = (Get-Content -Path $CredentialsFile).split(',')
$Username = $Credentials[0]
$PasswordSecure = $Credentials[1] | ConvertTo-SecureString
$BSTR = [System.Runtime.InteropServices.Marshal]::SecureStringToBSTR($PasswordSecure)
$PasswordInsecure = [System.Runtime.InteropServices.Marshal]::PtrToStringAuto($BSTR)

return $Username,$PasswordInsecure
