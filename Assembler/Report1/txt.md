# Задание 
Написать программу на ассемблере вычисления по формуле для знаковых и беззнаковых чисел. Для беззнаковых будем использовать типы данных byte и word, для знаковых – shortint и integer.   
![image](https://github.com/maesrto2000/EduExperience/assets/97037894/930750d4-9d32-4de1-b050-3fa39d39d86e)   
Для беззнаковых чисел:
```
program UNS;
var C: byte;
       B, Y: word;
begin
    B:=7;
    writeln (‘Enter C’);
    readln(C);
 asm
     mov AL, C
     mov BX, B
     mov CL, 1
     shl  CL, 1
     add  CL, AL
     CBW
     imul AL
     mov DX, AX
     shl AX, 1
     add AX, DX
     sub AX, CX
     sub AX, BX
     mov CL, 3
     sar AX, CL
     mov Y, AX
  end;
       writeln (‘Y=’, Y);
end.
```
Для знаковых чисел: 
```
program UNS;
var C: shortint;
       B, Y: integer;
begin
    B:=7;
    writeln (‘Enter C’);
    readln(C);
 asm
     mov AL, C
     mov BX, B
     mov CL, 1
     shal  CL, 1
     add  CL, AL
     CBW
     imul AL
     mov DX, AX
     shl AX, 1
     add AX, DX
     sub AX, CX
     sub AX, BX
     mov CL, 3
     sar AX, CL
     mov Y, AX
  end;
       writeln (‘Y=’, Y);
end.
