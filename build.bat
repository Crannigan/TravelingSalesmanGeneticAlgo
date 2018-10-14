@echo off

echo.

REM ***************************************** REM
REM                                           REM
REM PLEASE PUT THE CITY FILE NAMES IN QUOTES  REM
REM                                           REM
REM ***************************************** REM

if exist main.exe (
    del main.exe
)

g++ -o main main.cpp graph.cpp gene.cpp genePool.cpp
if %ERRORLEVEL% NEQ 0 (
    EXIT /b
)

main "cities.txt" "city_mileage.txt" 500 500