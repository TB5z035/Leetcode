@echo off
set HEADER="#include ^<bits/stdc++.h^>"
set NAMESPACE="using namespace std;"
set MAIN1="int main()"
set MAIN2="{"
set MAIN3="    return 0;"
set MAIN4="}"
mkdir %1
type nul>%1/%1.cpp
@echo %HEADER:"=%>>%1/%1.cpp
@echo %NAMESPACE:"=%>>%1/%1.cpp
@echo.>>%1/%1.cpp
@echo.>>%1/%1.cpp
@echo.>>%1/%1.cpp
@echo %MAIN1:"=%>>%1/%1.cpp
@echo %MAIN2:"=%>>%1/%1.cpp
@echo %MAIN3:"=%>>%1/%1.cpp
@echo %MAIN4:"=%>>%1/%1.cpp
