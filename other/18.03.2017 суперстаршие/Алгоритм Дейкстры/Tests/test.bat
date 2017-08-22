echo off
echo Test %2
copy %2 path.in
timer %1
check %2 %2.a path.out
pause
if exist path.in del path.in
if exist path.out del path.out