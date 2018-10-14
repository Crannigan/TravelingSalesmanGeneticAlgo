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

if exist *.o (
    del *.o
)

g++ -std=c++11 -c graph.cpp gene.cpp genePool.cpp
g++ -std=c++11 -o main main.cpp graph.o gene.o genePool.o
if %ERRORLEVEL% NEQ 0 (
    EXIT /b
)

if exist *.o (
    del *.o
)

 main "cities.txt" "city_mileage.txt" 500 500