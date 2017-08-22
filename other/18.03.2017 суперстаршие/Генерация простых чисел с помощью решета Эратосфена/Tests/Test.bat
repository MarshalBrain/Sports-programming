@echo off
@echo TEST %2
copy primes2.%2.in primes2.in
Timer %1
Check
pause
del primes2.in
del primes2.out