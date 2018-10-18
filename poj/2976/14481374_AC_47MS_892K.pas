
Const
  Eps=1e-6;

Var
  n,k:Longint;
  Ans:Double;
  a,b,c:Array [0..1000+100] of Longint;
  d:Array [0..1000+100] of Double;

Procedure Init;
  var
    i:longint;
  begin
    readln(n,k);
    if (n=0)and(k=0) then Halt;
    for i:=1 to n do read(a[i]);readln;
    for i:=1 to n do read(b[i]);readln;
  end;

procedure swap(var a,b:Longint);var t:Longint;begin t:=a;a:=b;b:=t;end;
procedure swap(var a,b:double);var t:Double;begin t:=a;a:=b;b:=t;end;

Procedure Qsort(l,r:Longint);
  var
    a,b:Longint;
    mid:Double;
  begin
    a:=l;b:=r;mid:=d[(l+r) shr 1];
    repeat
      while d[a]>mid do inc(a);
      while d[b]<mid do dec(b);
      if a<=b then
        begin
          swap(d[a],d[b]);
          swap(c[a],c[b]);
          inc(a);dec(b);
        end;
    until a>=b;
    if a<r then qsort(a,r);
    if l<b then qsort(l,b);
  end;

Procedure Main;
  var
    p,q:Int64;
    m,i:Longint;
    L:Double;
  begin
    //Dinkelbach
    m:=n-k;
    l:=1;
    Repeat
      Ans:=L;
      for i:=1 to n do begin d[i]:=a[i]-L*b[i];c[i]:=i;end;
      Qsort(1,n);
      p:=0;q:=0;
      for i:=1 to m do
        begin
          inc(p,a[c[i]]);
          inc(q,b[c[i]]);
        end;
      L:=p/q;
    Until abs(L-Ans)<Eps;
  end;

Procedure Print;
  begin
    writeln(Round(Ans*100));
  end;

Begin
  While True Do
    begin
      Init;
      Main;
      Print;
    end;
End.