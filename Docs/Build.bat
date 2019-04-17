# Install Chocolatey
@"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoProfile -InputFormat None -ExecutionPolicy Bypass -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))" && SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin"

# Install MongoDB
choco install mongodb -y

# Install MsBuild
choco install microsoft-build-tools

# Install nuget
choco install nuget.commandline

# Install Node.js

# Build C++ project
msbuild ..\Src\BackendAnalyzer\SourceCodeChecker.sln

# Install C# project dependencies
nuget restore ..\Src\Server\SeniorServer.sln

# Build C# project
msbuild ..\Src\Server\SeniorServer.sln

# Install JS project dependencies
npm install ..\Src\Client

pause