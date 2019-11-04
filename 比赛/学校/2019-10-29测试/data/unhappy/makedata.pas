program hhhhh;
var
        top:longint;

procedure make(i,f,a,s:longint);
var
        k,now:longint;
        ff:text;
        path:string;
begin
	str(top,path);inc(top);
        path:='unhappy'+path+'.in';
        assign(ff,path);
        rewrite(ff);
        writeln(ff,i+f+a+s,' ',random(1000));
        for k:=1 to i+f+a+s do
          if (random*4<1) and (i>0) then writeln(ff,'I ',random(100000)) else
          if (random*3<1) and (f>0) then begin writeln(ff,'F ',random(now)+1);inc(now);end else
          if (random*2<1) and (a>0) then writeln(ff,'A ',random(1000)) else
            writeln(ff,'S ',random(1000));
        close(ff);
end;
				
begin
	randomize;
	top:=0;
        {I,F,A,S}
        make(3,3,2,2);
        make(4,4,3,3);
        make(10,10,3,3);
        make(11,11,4,4);
        make(100,100,10,10);
        make(101,101,11,11);
        make(1000,1000,30,30);
        make(1001,1001,31,31);
        make(5000,5000,50,50);
        make(5001,5001,51,51);
        make(10000,10000,60,60);
        make(10001,10001,61,61);
        make(20000,20000,70,70);
        make(20001,20001,71,71);
        make(50000,50000,80,80);
        make(50001,50001,81,81);
        make(80000,80000,90,90);
        make(80001,80001,91,91);
        make(99999,99999,99,99);
        make(100000,100000,100,100);
end.
