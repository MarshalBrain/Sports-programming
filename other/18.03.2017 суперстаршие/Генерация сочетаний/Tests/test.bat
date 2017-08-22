echo off

echo TEST1
del b.in
del b.out
copy 01 b.in
%1
check b.in b.out 01.a
pause

echo TEST2
del b.in
del b.out
copy 02 b.in
%1
check b.in b.out 02.a
pause

echo TEST3
del b.in
del b.out
copy 03 b.in
%1
check b.in b.out 03.a
pause

echo TEST4
del b.in
del b.out
copy 04 b.in
%1
check b.in b.out 04.a
pause

echo TEST5
del b.in
del b.out
copy 05 b.in
%1
check b.in b.out 05.a
pause

echo TEST6
del b.in
del b.out
copy 06 b.in
%1
check b.in b.out 06.a
pause

echo TEST7
del b.in
del b.out
copy 07 b.in
%1
check b.in b.out 07.a
pause
