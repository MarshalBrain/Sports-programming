{$I-,S-,Q-,R-}
Program Solution;
type
  PList = ^TList;
  TList = Record
    Num: LongInt;
    C, F: LongInt;
    Rev, Next: PList;
  end;

var
  Result: LongInt;
  Edg: Array[1..800] of PList;
  A: Array[1..800, 1..800] of LongInt;
  Used: Array[1..800] of Boolean;
  Min: Array[1..800] of LongInt;
  Prev: Array[1..800] of PList;
  Q: Array[1..800] of LongInt;
  QBeg, QEnd: LongInt;
  S, T: LongInt;
  X, Y, Z: LongInt;
  N, M: LongInt;

Procedure InputData;
var
  i: LongInt;

begin
  Assign(Input, 'input.txt');
  ReSet(Input);
  ReadLn(N);
  ReadLn(M);
  FillChar(A, SizeOf(A), 0);
  For i:= 1 to M do begin
    ReadLn(X, Y, Z);
    A[X, Y]:= Z;
  end;
  ReadLn(S);
  ReadLn(T);
  Close(Input);
end;

Function MinLongInt(A, B: LongInt): LongInt;
begin
  If A < B
    then MinLongInt:= A
    else MinLongInt:= B;
end;

Procedure Solve;
var
  i, j: LongInt;
  X, Adj: PList;
  TNum: LongInt;

begin
  For i:= 1 to N-1 do
    For j:= i+1 to N do
      If (A[i, j] > 0) or (A[j, i] > 0) then begin
        New(X);
        X^.Num:= j;
        X^.Next:= Edg[i];
        X^.C:= A[i, j];
        X^.F:= 0;
        Edg[i]:= X;
        New(X);
        X^.Num:= i;
        X^.Next:= Edg[j];
        X^.C:= A[j, i];
        X^.F:= 0;
        Edg[j]:= X;
        Edg[i]^.Rev:= Edg[j];
        Edg[j]^.Rev:= Edg[i];
      end;
  Result:= 0;
  While True do begin
    FillChar(Used, SizeOf(Used), False);
    FillChar(Min, SizeOf(Min), 0);
    QBeg:= 0;
    QEnd:= 0;
    Inc(QBeg);
    Q[QBeg]:= S;
    Used[S]:= True;
    Min[S]:= 2000000000;
    Prev[S]:= nil;
    While QEnd < QBeg do begin
      Inc(QEnd);
      TNum:= Q[QEnd];
      Adj:= Edg[TNum];
      While Adj <> nil do begin
        If (not Used[Adj^.Num]) and (Adj^.F < Adj^.C) then begin
          Used[Adj^.Num]:= True;
          Min[Adj^.Num]:= MinLongInt(Min[TNum], Adj^.C-Adj^.F);
          Prev[Adj^.Num]:= Adj;
          Inc(QBeg);
          Q[QBeg]:= Adj^.Num;
        end;
        Adj:= Adj^.Next;
      end;
    end;
    If not Used[T] then Break;
    Inc(Result, Min[T]);
    TNum:= T;
    While TNum <> S do begin
      Inc(Prev[TNum]^.F, Min[T]);
      Dec(Prev[TNum]^.Rev^.F, Min[T]);
      TNum:= Prev[TNum]^.Rev^.Num;
    end;
  end;
end;

Procedure WriteData;
begin
  Assign(Output, 'output.txt');
  ReWrite(Output);
  WriteLn(Result);
  Close(Output);
end;

begin
  InputData;
  Solve;
  WriteData;
end.