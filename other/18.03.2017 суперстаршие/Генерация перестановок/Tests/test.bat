echo off

echo TEST1
del a.in
del a.out
copy 01 a.in
%1
check a.in a.out 01.a
pause

echo TEST2
del a.in
del a.out
copy 02 a.in
%1
check a.in a.out 02.a
pause

echo TEST3
del a.in
del a.out
copy 03 a.in
%1
check a.in a.out 03.a
pause

echo TEST4
del a.in
del a.out
copy 04 a.in
%1
check a.in a.out 04.a
pause

echo TEST5
del a.in
del a.out
copy 05 a.in
%1
check a.in a.out 05.a
pause

echo TEST6
del a.in
del a.out
copy 06 a.in
%1
check a.in a.out 06.a
pause

