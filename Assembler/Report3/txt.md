# Задание 
Дан массив А из К элементов и массив В из М элементов. Сформировать массив С, являющийся пересечением двух заданных, т.е. включить в него элементы, принадлежащие одновременно двум массивам А и В.
```
const K := 3;
      M := 3;
      O := 9;
var a: array [1...K] of integer;
b: array [1...M] of integer;
c: array [1...O] of integer;
i: 1...K;
j: 1...M;
p: 1...O;

begin

  writeln(‘enter 5 elements’);
    for i:= 1 to K do
       readln(a[i]);


  writeln(‘enter 5 elements’);
    for j:= 1 to M do
       readln(b[j]);

  asm
   lea SI,a
   lea DI,b
   lea BX,c
   mov CX,K
@l1:push CX
    mov CX,M
    mox ax,[SI]
@l2:cmp ax,[DI]
    jne @z
    mov [BX],ax
    inc BX
    inc BX
 @z:inc DI
    inc DI
    loop @l2
    pop CX
    inc SI
    inc SI
    loop @l1
  end;

  for p:1 to O do
    begin
      write (c[p]:6)
    end;
end.

