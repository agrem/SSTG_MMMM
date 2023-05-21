cls
@echo off

@set SOURCES=main.cpp
@set OUT_EXE=zz.exe
@set LIBRARIES=
@set INCLUDESDIR=
@set OPTIONS=-flto -Wall -Wextra -O2 -std=c++17

if exist zz.exe (del zz.exe)
@echo   ===========    KOMPILUJĘ     ==========
@echo on
g++ -o %OUT_EXE% %SOURCES% %OPTIONS% 
zz.exe
