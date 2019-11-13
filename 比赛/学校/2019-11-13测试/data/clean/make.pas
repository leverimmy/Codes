var len,n:longint;
  begin
    assign(output,'clean.in');
    rewrite(output);
    len:=500000; n:=500000;
    writeln(len,' ',n);
    randomize;
    for n:=1 to n do writeln(random(200000)+random(10000)+random(10000)+10000,' ',random(270000)+230000);
    close(output);
  end.
