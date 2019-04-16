"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe" ..\Src\BackendAnalyzer\SourceCodeChecker.sln
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe" ..\Src\Server\SeniorServer.sln /t:restore
cd ..\Src\Client
npm install
npm run dev
