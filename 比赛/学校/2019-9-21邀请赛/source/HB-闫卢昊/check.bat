:again
data3>in.txt
bf3<in.txt>c.txt
array<in.txt>t.txt
fc t.txt c.txt
if not errorlevel 1 goto again
pause
