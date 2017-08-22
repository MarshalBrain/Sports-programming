@echo off
@echo TEST %2
copy %2.in input.txt
timer %1
rem copy output.txt %2.out
fc %2.out output.txt /w
pause
if exist input.txt del input.txt
if exist output.txt del output.txt

