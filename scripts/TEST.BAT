@ECHO OFF
CD ..

ECHO [32mCleaning up project files[0m
RD /S /Q RouteHelper\bin > NUL 2>&1
RD /S /Q RouteHelper\obj > NUL 2>&1
RD /S /Q RouteHelperTester\bin > NUL 2>&1
RD /S /Q RouteHelperTester\obj > NUL 2>&1

ECHO [32mCompiling the project[0m
MSBuild /t:Rebuild /p:Configuration=Release;Platform=x64 Netch.sln
MSBuild /t:Rebuild /p:Configuration=Release;Platform=x86 Netch.sln

ECHO [32mProcessing dependencies[0m
COPY /Y RouteHelper\bin\Release\x64\RouteHelper.dll RouteHelperTester\bin\x64\Release\
COPY /Y RouteHelper\bin\Release\Win32\RouteHelper.dll RouteHelperTester\bin\x86\Release\


ECHO [32mTesting x64 platform[0m
CD RouteHelperTester\bin\x64\Release
RouteHelperTester

ECHO [32mTesting x86 platform[0m
CD ..\..\x86\Release
RouteHelperTester

PAUSE