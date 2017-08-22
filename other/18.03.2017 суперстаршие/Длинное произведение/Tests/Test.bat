@echo off
@echo TEST %2
copy longprod.%2.in longprod.in
Timer %1
Check
pause
del longprod.in
del longprod.out