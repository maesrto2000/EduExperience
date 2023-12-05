# Задание 
Скопировать текстовый файл, зеркально поменяв порядок строк
```
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
#include <malloc.h> 
#include <stdlib.h> 
#define MAXLEN 1000 
#define NLINES 1000 
int main()
{
	FILE *fp, *fp2;
	char** lines;
	int i;
	int nlines = 0; 
	fp = fopen("Text.txt", "rt");
	fp2 = fopen("Text2.txt", "wt");
	if (fp == NULL)
		return;
	lines = (char**)malloc(NLINES * sizeof(char*));
	memset(lines, 0, NLINES * sizeof(char*));
	while (!feof(fp))
	{
		char line[MAXLEN];
		char *ptr = fgets(line, MAXLEN, fp);
		int len; //длина текущей строки 
		if (ptr == NULL)    break; 
		len = (int)strlen( line ); 
		if (nlines >= NLINES)
		{
			lines = (char**)realloc(lines, (nlines + 1) * sizeof(char*));
			lines[nlines] = 0;
		}
		if (line[len - 1] == '\n')
			line[len - 1] = 0;
		lines[nlines] = (char*)malloc(len+1);
		strcpy(lines[nlines], line); 
		nlines++;
	}
	for (i = nlines-1 ;i >= 0;i--)
		fprintf(fp2,"%s\n", lines[i]);
	fclose(fp);
	fclose(fp2);
	for (i = 0; i < nlines; i++)
	{
		if (lines[i] != NULL)
			free(lines[i]);
	}

	if( lines != NULL ) 
		free(lines);
	return 0;
}
