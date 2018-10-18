var f:array[0..100000] of boolean; 
   t:array[0..100000] of longint; 
   a,c:array[1..100] of longint; 
   i,k,n,m,ans:longint;
begin 
   readln(n,m);
   while not((n=0) and (m=0)) do 
   begin 
   for i:=1 to n do read(a[i]); 
   for i:=1 to n do read(c[i]);
   fillchar(f,sizeof(f),false); 
   f[0]:=true;ans:=0;
   for i:=1 to n do 
   begin 
   fillchar(t,sizeof(t),0); 
   for k:=a[i] to m do 
   if not f[k] and f[k-a[i]] then 
   if(t[k-a[i]]<c[i]) then 
   begin 
   f[k]:=true;
   t[k]:=t[k-a[i]]+1; 
   end; 
   end; 
   for i:=1 to m do 
   if f[i] then inc(ans); 
   writeln(ans);
   readln(n,m); 
   end; 
end.