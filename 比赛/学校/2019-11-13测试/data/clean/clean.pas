var  i,j,a,b,c,n,m,ans,q,last,start:longint;
     x:array [1..500001] of int64;
     p:boolean;  ch:char;
begin
 // for ch:='7' to '9' do
   ch:='0';
  begin
  assign(input,'clean1'+ch+'.in');
  assign(output,'clean1'+ch+'.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  fillchar(x,sizeof(x),0);
  last:=0; start:=maxlongint;
  for i:=1 to m do
   begin
     readln(a,b);
    // if a<=10000 then begin p:=true; writeln(i); halt end;
     x[a]:=x[a]+1;
     x[b+1]:=x[b+1]-1;
   end;
  q:=0;    ans:=0;
  for i:=1 to n do
   begin
     q:=q+x[i];
     if q=0 then ans:=ans+1;
   end;
   //if  p then
  writeln(ans);
  close(input);
  close(output);
  end;
end.
