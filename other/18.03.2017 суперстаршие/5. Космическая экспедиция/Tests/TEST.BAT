@echo off
@echo Test %1
@echo Test %1 >>%2.res
if exist input.txt del input.txt
if exist output.txt del output.txt
copy %1.in input.txt >nul
wintimer %2.exe 1000 >>%2.res
if exist output.txt goto next
@echo No output file! >>%2.res
goto end
:next
fc /a %1.out output.txt >>%2.res
:end
