@echo off


for /f "delims=" %%a in ('dir /ad/b "%cd%"') do (
	for /f "delims=" %%b in ('dir /ad/b "%cd%/%%a"') do ( 
		copy %cd%\%%a\%%b\%%b.cpp %cd%\%%a\%%b.cpp
		copy %cd%\%%a\%%b\%%b.pas %cd%\%%a\%%b.pas
		copy %cd%\%%a\%%b\%%b.c %cd%\%%a\%%b.c
		copy %cd%\%%a\%%b\%%b0.out %cd%\%%a\%%b0.out
		copy %cd%\%%a\%%b\%%b1.out %cd%\%%a\%%b1.out
		copy %cd%\%%a\%%b\%%b2.out %cd%\%%a\%%b2.out
		copy %cd%\%%a\%%b\%%b3.out %cd%\%%a\%%b3.out
		copy %cd%\%%a\%%b\%%b4.out %cd%\%%a\%%b4.out
		copy %cd%\%%a\%%b\%%b5.out %cd%\%%a\%%b5.out
		copy %cd%\%%a\%%b\%%b6.out %cd%\%%a\%%b6.out
		copy %cd%\%%a\%%b\%%b7.out %cd%\%%a\%%b7.out
		copy %cd%\%%a\%%b\%%b8.out %cd%\%%a\%%b8.out
		copy %cd%\%%a\%%b\%%b9.out %cd%\%%a\%%b9.out
		copy %cd%\%%a\%%b\%%b10.out %cd%\%%a\%%b10.out
		copy %cd%\%%a\%%b\%%b11.out %cd%\%%a\%%b11.out
		copy %cd%\%%a\%%b\%%b12.out %cd%\%%a\%%b12.out
		copy %cd%\%%a\%%b\%%b13.out %cd%\%%a\%%b13.out
		copy %cd%\%%a\%%b\%%b14.out %cd%\%%a\%%b14.out
		copy %cd%\%%a\%%b\%%b15.out %cd%\%%a\%%b15.out
		copy %cd%\%%a\%%b\%%b16.out %cd%\%%a\%%b16.out
		copy %cd%\%%a\%%b\%%b17.out %cd%\%%a\%%b17.out
		copy %cd%\%%a\%%b\%%b18.out %cd%\%%a\%%b18.out
		copy %cd%\%%a\%%b\%%b19.out %cd%\%%a\%%b19.out
		del %cd%\%%a\%%b\*.in
		del %cd%\%%a\%%b\*.exe
		del %cd%\%%a\*.in
		del %cd%\%%a\*.exe
	)
)