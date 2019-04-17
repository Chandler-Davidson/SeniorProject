:: Install Chocolatey
@"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoProfile -InputFormat None -ExecutionPolicy Bypass -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))" && SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin"

:: Refresh PATH environment
:: Get System PATH
for /f "tokens=2*" %%A in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v Path') do set syspath=%%B

:: Get User Path
for /f "tokens=2*" %%A in ('reg query "HKCU\Environment" /v Path') do set userpath=%%B

:: Set Refreshed Path
set PATH=%userpath%;%syspath%

:: Install MongoDB
choco upgrade mongodb -y

:: Install nuget
choco upgrade nuget.commandline -y

:: Install Node.js
choco upgrade nodejs -y

:: Refresh PATH environment
:: Get System PATH
for /f "tokens=2*" %%A in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v Path') do set syspath=%%B

:: Get User Path
for /f "tokens=2*" %%A in ('reg query "HKCU\Environment" /v Path') do set userpath=%%B

:: Set Refreshed Path
set PATH=%userpath%;%syspath%

:: Move to local directory
@setlocal enableextensions
@cd /d "%~dp0"

:: Build C++ project
%ProgramFiles(x86)%\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe" ..\Src\BackendAnalyzer\SourceCodeChecker.sln

 :: Install C# project dependencies
nuget restore ..\Src\Server\SeniorServer.sln

 :: Build C# project
"%ProgramFiles(x86)%\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe" ..\Src\Server\SeniorServer.sln

:: Install JS project dependencies
npm install ..\Src\Client

pause
