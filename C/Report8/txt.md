# Задание 
В новом файле в четных  строках перед последним словом указать его позицию исходного файла в строке.
```
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXLINE 1000
#define NO 0
#define YES 1
int main(void)
{
	char tmp[MAXLINE]; 
	char a[MAXLINE]; 
	int i = 0, flag, w=0, strnum=1, pos=0;
	FILE *fpin;
	FILE *fpout;
	fpin = fopen("test.txt", "rt"); 
	if (fpin == NULL)   
		return;
	fpout = fopen("result.txt", "wt");
	if (fpout == NULL)
		return;
	while (!feof(fpin))
	{
		flag = NO; 
		fgets(a , MAXLINE, fpin); 
		if (strnum % 2 == 0) 
		{
			i = 0;
			while (a[i] != '\0')
			{
				if (a[i] == ' ' || a[i] == ',' || a[i] == '\0' || a[i] == '\n') 
				{
					if (flag == YES)
					{
						flag = NO;
						w++;
					}
				}
				else 
					if (flag == NO)
					{
						pos = i; 
						flag = YES;
					}
				i++; 
			}
			for (i = 0; i < pos; i++) 
				fputc(a[i], fpout);
			itoa(w, tmp, 10);
			fputs(tmp, fpout);
			while (a[i] != '\0') 
			{
				fputc(a[i++], fpout);
			}
		}
		else
			fputs(a, fpout);
		w = 0;
		strnum++;
		pos = 0;
	}
	fclose(fpin); 
	fclose( fpout); 
	return 0;
}
