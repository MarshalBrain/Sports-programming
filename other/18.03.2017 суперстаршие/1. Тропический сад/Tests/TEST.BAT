@echo off
@echo Test %1
@echo Test %1 >>%2.res
if exist poliv.in del poliv.in
if exist poliv.out del poliv.out
copy %1.in poliv.in >nul
Timer %2.exe 3000 >>%2.res
if exist poliv.out goto next
@echo No output file! >>%2.res
goto end
:next
Checker.exe Poliv.out %1.out >>%2.res
:end