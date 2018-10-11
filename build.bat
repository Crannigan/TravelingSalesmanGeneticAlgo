@echo off

echo.

REM ***************************************** REM
REM                                           REM
REM PLEASE PUT THE CITY FILE NAMES IN QUOTES  REM
REM                                           REM
REM ***************************************** REM

if exist main.o (
    del main.o
)

if exist Graph.o (
    del Graph.o
)

if exist main.exe (
    del main.exe
)

g++ -c Graph.cpp
if %ERRORLEVEL% NEQ 0 (
    EXIT /b
)

g++ -c main.cpp
if %ERRORLEVEL% NEQ 0 (
    EXIT /b
)

g++ -o main.exe Graph.o main.o
if %ERRORLEVEL% NEQ 0 (
    EXIT /b
)
main "cities.txt" "city_mileage.txt" 500 500