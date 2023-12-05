# Задание 
Скопировать содержимое текстового файла, удалив строку с наибольшим количеством слов.
```
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define MAXLINE 1024 
int wordsCount(char*s) 
{
	int counter = 0;
	while (*s!='\0') 
	{
		if (*s != ' ' && *s != '\n' && *s!='.' && *s!=',')
		{
			counter++;
			while (*s != ' ' && *s != '.' && *s != ',' && *s != '\0')
			{
				s++;
			}
		}
		s++;
	}
	return counter; 
}
int main(void)
{  
	FILE *fpin;     
	FILE *fpout;
	char line[MAXLINE]; 
	char *ptr; 
	int i = 0, maxLine = 0, count, maxCount = 0;

 
	fpin = fopen( "Text.txt", "rt" );   
	if (fpin == NULL)   
		return;  

	
	fpout = fopen("TextFile2.txt", "wt" );  
	if (fpout == NULL)
		return;  
	while (!feof(fpin))// цикл до конца файла  
	{   
		ptr = fgets( line, MAXLINE, fpin );  

		if (ptr == NULL)    
			break; 
		count = wordsCount(line);
		if (count > maxCount)
		{
			maxCount = count;
			maxLine = i;
		}
		i++;
	} 
	rewind(fpin); 
	i = 0;
	while (!feof(fpin))
	{  
		ptr = fgets(line, MAXLINE, fpin);
		if (i != maxLine)
		{
			fputs( line, fpout /* указатель на выходной файл */ );
		}
		i++;
	} 
	fclose(fpin); 
	fclose( fpout ); 
	return 0;
}
