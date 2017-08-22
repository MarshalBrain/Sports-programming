echo off

echo TEST1
del c.in
del c.out
copy 01 c.in
%1
check c.in c.out 01.a
pause

echo TEST2
del c.in
del c.out
copy 02 c.in
%1
check c.in c.out 02.a
pause

echo TEST3
del c.in
del c.out
copy 03 c.in
%1
check c.in c.out 03.a
pause

echo TEST4
del c.in
del c.out
copy 04 c.in
%1
check c.in c.out 04.a
pause

echo TEST5
del c.in
del c.out
copy 05 c.in
%1
check c.in c.out 05.a
pause

echo TEST6
del c.in
del c.out
copy 06 c.in
%1
check c.in c.out 06.a
pause
