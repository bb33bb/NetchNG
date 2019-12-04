@ECHO OFF
CD ..

ECHO Cleaning up project files
RD /S /Q RouteHelper\bin > NUL 2>&1
RD /S /Q RouteHelper\obj > NUL 2>&1
RD /S /Q RouteHelperTester\bin > NUL 2>&1
RD /S /Q RouteHelperTester\obj > NUL 2>&1

PAUSE