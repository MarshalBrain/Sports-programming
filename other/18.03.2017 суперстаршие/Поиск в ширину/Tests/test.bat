echo off
echo Test %2
copy %2.in path.in
timer %1
fc path.out %2.out /w
pause
if exist path.in del path.in
if exist path.out del path.out