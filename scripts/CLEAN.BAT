@ECHO OFF
CD ..

ECHO [32mCleaning up project files[0m
RD /S /Q RouteHelper\bin > NUL 2>&1
RD /S /Q RouteHelper\obj > NUL 2>&1
RD /S /Q RouteHelperTester\bin > NUL 2>&1
RD /S /Q RouteHelperTester\obj > NUL 2>&1

PAUSE