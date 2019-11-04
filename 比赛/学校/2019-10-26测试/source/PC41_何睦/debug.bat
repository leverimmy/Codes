:loop
	rnd.exe
	seq_bf.exe
	seq.exe
	fc seq.out seq.ans
	if errorlevel 1 pause
	goto loop
