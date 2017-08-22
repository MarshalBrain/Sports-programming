@echo off
if exist %1.exe del %1.exe
C:\FPC\2.2.2\bin\i386-win32\fpc.exe -O2 %1.pas
if exist %1.o del %1.o
if exist %1.res del %1.res
if not exist %1.exe goto bb
echo Задача: Такси >>%1.res 
echo Program to test: %1 >>%1.res
echo ................ >>%1.res 
for %%i in (1,2,3,4,5,6,7,8,9,10) do call test.bat %%i %1
if exist input.txt del input.txt>Nul
if exist output.txt del output.txt>Nul
if exist %1.exe del %1.exe>Nul
if exist %1.pas del %1.pas>Nul
bb: