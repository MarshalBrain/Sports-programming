var n,m,k,l,i:integer;
    a1,a2,a3,b1,b2,b3:integer;
    p,rank:array [0..1000000] of longint;
procedure create(x:longint);
begin
p[x]:=x;
rank[x]:=0;
end;
function search(x:longint):longint;
begin
if x<>p[x] then p[x]:=search(p[x]);
search:=p[x];
end;
procedure ob(x,y:longint);
begin
if rank[x]>rank[y] then p[y]:=x
else p[x]:=y;
if rank[x]=rank[y] then inc(rank[y]);
end;

procedure obr(b,a:longint);
  var c:integer;
begin
c:=b div 10000;
if c=0 then write(100,' ')
else write(c,' ');
c:=b div 100 mod 100;
if c=0 then write(100,' ')
else write(c,' ');
c:=b mod 100;
if c=0 then write(100,' ')
else write(c,' ');
c:=a div 10000;
if c=0 then write(100,' ')
else write(c,' ');
c:=a div 100 mod 100;
if c=0 then write(100,' ')
else write(c,' ');
c:=a mod 100;
if c=0 then writeln(100)
else writeln(c);
end;
procedure next(a,b:longint);
begin
if search(a)=0 then
  begin
    create(a);
    ob(search(a),search(b));
  end
else
  if search(a)<>search(b) then
    ob(search(a),search(b))
  else obr(b,a);
end;

procedure start;
  var n,k,i,j,c,c1,d,n1:longint;
begin
if a1=100 then a1:=0;
if a2=100 then a2:=0;
if a3=100 then a3:=0;
if b1=100 then b1:=0;
if b2=100 then b2:=0;
if b3=100 then b3:=0;
n:=a3+a2*100+a1*10000;
k:=b3+b2*100+b1*10000;
if a1<>b1 then
  begin
    j:=10000;
    c:=a1;
    c1:=b1;
  end
else if a2<>b2 then
  begin
    j:=100;
    c:=a2;
    c1:=b2;
  end
else
  begin
    j:=1;
    c:=a3;
    c1:=b3;
  end;
if search(n)=0 then create(n);
if c=0 then c:=100;
if c1=0 then c1:=100;
d:=abs(c-c1);
if c>c1 then
  for i:=2 to d do
    if c=100 then
      begin
        n1:=n;
        n:=n+j*99;
        c:=0;
        next(n,n1);
      end
    else
      begin
        n1:=n;
        n:=n-j;
        next(n,n1);
    end
else
  for i:=2 to d do
    begin
      n1:=n;
      inc(c);
      if c=100 then
        n:=n-j*99
      else
        n:=n+j;
      next(n,n1);
    end;
next(k,n);
end;

begin
assign(input,'input.txt');
reset(input);
assign(output,'output.txt');
rewrite(output);
read(n,m,k,l);
for i:=1 to l do
  begin
    read(a1,a2,a3,b1,b2,b3);
    start;
  end;
close(input);
close(output);
end.