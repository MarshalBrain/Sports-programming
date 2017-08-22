@echo off
@echo TEST %2
copy %2.in input.txt
Timer %1
checker.py %2
pause
if exist input.txt del input.txt
if exist output.txt del output.txt

