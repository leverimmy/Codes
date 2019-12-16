uses dos,crt;
var i,j,k,l,o,p:longint;
    s,ss:string;
    s1:ansistring;
    f:text;

procedure cover(f1,f2:string);
begin
    assign(input,f1);reset(input);
    assign(output,f2);rewrite(output);
      while not(eof(input)) do begin
        readln(s1);
        writeln(s1);
      end;
    close(input);
    close(output);
end;

begin
  assign(input,'');reset(input);
  assign(output,'');rewrite(output);
    writeln('please prepare the ''make.exe'' and std named as file name');
    writeln('Please enter file name:');
    readln(ss);
    writeln('Please enter start number:');
    readln(o);
    writeln('Please enter end number:');
    readln(p);
  close(output);
  close(input);
  assign(f,'');rewrite(f);
  for i:=o to p do begin
    str(i,s);
    cover(ss+s+'.in',ss+'.in');
    exec(ss,'');
    cover(ss+'.out',ss+s+'.ans');
    writeln(f,i,' ok');
  end;
  writeln(f,'ok');
close(f);
  assign(f,'');reset(f);
  readln(f);
close(f);
end.
