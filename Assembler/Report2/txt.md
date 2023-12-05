# Задание 
Записать в ячейку P единицу, если числа A, C и B имеют одинаковую четность.
```
var p:word;
      a, b, c:byte;
begin
             writeln('Enter a b c');
              readln(a, b, c);
       asm
	  mov p, 0
	  mov ax, a
	  add ax, b
	  test ax, 1
	  JNZ @l
              mov ax, a
	  add ax, c
	  test ax, 1
	  JNZ @l
              inc p
        @l: nop
    end;
  	if p = 0 then
		         writeln('not same')
		else
		         writeln('same')
end.
