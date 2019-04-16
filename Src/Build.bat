"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe" BackendAnalyzer\SourceCodeChecker.sln
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe" Server\SeniorServer.sln /t:restore
cd Client
npm install
npm run dev
