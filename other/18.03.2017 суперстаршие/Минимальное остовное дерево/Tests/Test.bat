@echo off
@echo TEST %2
copy Input%2.txt input.txt
%1
Checker Input%2.txt output.txt Answer%2.txt
pause
if exist input.txt del input.txt
if exist output.txt del output.txt
