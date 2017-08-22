@echo off
@echo TEST %2
copy primes.%2.in primes.in
Timer %1
Check
pause
del primes.in
del primes.out