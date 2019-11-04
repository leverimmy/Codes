program hhhhh;
const
        path='19';
        maxn=210000;
var
        left,right,key,deep,s:array[1..maxn] of longint;
        tt,root,kk,who:longint;
        inf,outf:string;
function max(a,b:longint):longint;
begin
        if a>b then exit(a)
               else exit(b);
end;

function updata(t:longint):longint;
var
        a,b:longint;
begin
        a:=deep[left[t]];b:=deep[right[t]];
        deep[t]:=max(a,b)+1;
        s[t]:=s[left[t]]+s[right[t]]+1;
        exit(a-b);
end;

function lr(t:longint):longint;
begin
        kk:=right[t];
        right[t]:=left[kk];
        left[kk]:=t;
        updata(t);
        updata(kk);
        exit(kk);
end;

function rr(t:longint):longint;
begin
        kk:=left[t];
        left[t]:=right[kk];
        right[kk]:=t;
        updata(t);
        updata(kk);
        exit(kk);
end;

function maintain(var t:longint):longint;
begin
        kk:=updata(t);
        if kk<-1 then begin
          if (updata(right[t])>0) then right[t]:=rr(right[t]);
          t:=lr(t);
          end
                 else
        if kk>1 then begin
          if (updata(left[t])<0) then left[t]:=lr(left[t]);
          t:=rr(t);
          end;
        exit(t);
end;

function insert(t,v:longint):longint;
begin
        if t=0 then begin inc(tt);key[tt]:=v;t:=tt;end
               else
        if v<key[t] then left[t]:=insert(left[t],v)
                    else right[t]:=insert(right[t],v);
        t:=maintain(t);
        exit(t);
end;

function del(t,v:longint):longint;
begin
        if (v=key[t]) or ((v<key[t]) and (left[t]=0)) then begin
          if (left[t]=0) or (right[t]=0) then begin
            who:=t;
            exit(left[t]+right[t]);
            end;
          right[t]:=del(right[t],v-1);
          key[t]:=key[who];
          end
                        else
        if v<key[t] then left[t]:=del(left[t],v) else
                         right[t]:=del(right[t],v);
        t:=maintain(t);
        exit(t);
end;

function select(t,k:longint):longint;
begin
        while (k<>s[left[t]]+1) do
          if k<=s[left[t]] then t:=left[t]
                           else begin k:=k-s[left[t]]-1;t:=right[t]; end;
        exit(t);
end;

procedure main;
var
        k,task,min,now,total,ans,j:longint;
        ch:char;
begin
        assign(input,inf); reset(input);
        assign(output,outf); rewrite(output);
        readln(task,min);
        now:=0;total:=0;ans:=0;
        for task:=1 to task do begin
          read(ch);readln(k);
          if ch='I' then begin
            if k>=min then begin
              k:=k-now;
              inc(total);
              root:=insert(root,k);
              end;
            end
                    else
          if ch='A' then now:=now+k else
          if ch='S' then begin
            now:=now-k;
            while total>0 do begin
              j:=select(root,1);
              if key[j]+now<min then begin
                dec(total);
                inc(ans);
                root:=del(root,key[j]);
                end
                                else break;
              end;
            end
                    else
          if ch='F' then begin
            if k<=total then begin
              j:=select(root,total+1-k);
              writeln(key[j]+now);
              end
                        else
              writeln(-1);
            end;
          end;
        writeln(ans);
        close(input); close(output);
end;

begin
        inf:='unhappy'+path+'.in';
        outf:='unhappy'+path+'.out';
        main;
end.
