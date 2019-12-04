@ECHO OFF
CD ..

ECHO Cleaning up project files
RD /S /Q RouteHelper\bin > NUL 2>&1
RD /S /Q RouteHelper\obj > NUL 2>&1
RD /S /Q RouteHelperTester\bin > NUL 2>&1
RD /S /Q RouteHelperTester\obj > NUL 2>&1

ECHO Compiling the project
MSBuild /t:Rebuild /p:Configuration=Release;Platform=x64 Netch.sln
MSBuild /t:Rebuild /p:Configuration=Release;Platform=x86 Netch.sln

ECHO Processing dependencies
COPY /Y RouteHelper\bin\Release\x64\RouteHelper.dll RouteHelperTester\bin\x64\Release\
COPY /Y RouteHelper\bin\Release\Win32\RouteHelper.dll RouteHelperTester\bin\x86\Release\

ECHO Testing x64 platform
CD RouteHelperTester\bin\x64\Release
RouteHelperTester

ECHO Testing x86 platform
CD ..\..\x86\Release
RouteHelperTester

PAUSE