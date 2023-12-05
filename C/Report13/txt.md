# Задание 
Вывести на экран содержимое файла с программой на языке С, выделяя в строке все макроимена.
```
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define LETTER 1
#define NOT_THE_LETTER 0 
#define MAXLEN 1000

			int main(void)
			{
				HANDLE hStdout;
				FILE* fp;
				char line[MAXLEN];
				char word[MAXLEN];

				char defines[10][MAXLEN];
				int definesCount = 5;
				int isDefine = 0;
				int define_flag = 0;
				strcpy(defines[0], "__TIME__");
				strcpy(defines[1], "__FILE__");
				strcpy(defines[2], "__LINE__");
				strcpy(defines[3], "__DATE__");
				strcpy(defines[4], "__TIMESTAMP__");

				int i;
				int flag;
				int prev_flag;
				char* ptr;
				WORD foregroundColor0;
				WORD foregroundColor1;
				WORD foregroundColor;
				WORD backgroundColor;
				WORD textAttribute;
				hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
				foregroundColor0 = FOREGROUND_INTENSITY |
					FOREGROUND_BLUE |
					FOREGROUND_GREEN;
				foregroundColor1 = FOREGROUND_INTENSITY |
					FOREGROUND_RED;
				backgroundColor = BACKGROUND_INTENSITY |
					BACKGROUND_BLUE |
					BACKGROUND_GREEN |
					BACKGROUND_RED;

				SetConsoleTextAttribute(hStdout,
					foregroundColor0 | backgroundColor);
				fp = fopen("test.txt", "rt");
				if (fp == NULL)
					return;
				while (!feof(fp))
				{
					ptr = fgets(line, MAXLEN, fp);
					if (ptr == NULL)
						break;

					i = 0;
					prev_flag = flag = NOT_THE_LETTER;

					word[0] = '\0';
					while (*ptr != 0)
					{
						prev_flag = flag;

						if (*ptr == ' ' || *ptr == ',' ||
							*ptr == '.' || *ptr == '\n' ||
							*ptr == '[' || *ptr == ']' ||
							*ptr == ';' || *ptr == ')' ||
							*ptr == '(')
							flag = NOT_THE_LETTER;
						else
							flag = LETTER;

						if (flag != prev_flag)
						{
							word[i] = '\0';

							for (int i = 0; i < definesCount; i++)
							{
								if (strcmp(defines[i], word) == 0)
								{
									define_flag = 1;
									break;
								}
							}

							foregroundColor = (define_flag == 0) ? foregroundColor0 : foregroundColor1;
							textAttribute = foregroundColor | backgroundColor;
							SetConsoleTextAttribute(hStdout, textAttribute);

							printf("%s", word);

							if (strcmp(word, "#define") == 0)
							{
								isDefine = 1;
								int h = 0;
								*ptr++;
								while (*ptr != ' ' && *ptr != 0 && *ptr != '\n')
								{
									defines[definesCount][h] = *ptr++;
									h++;
									defines[definesCount][h] = 0;
								}
								printf(" %s", defines[definesCount]);
								definesCount++;
							}

							i = 0;
							define_flag = 0;
						}
						word[i++] = *ptr++;
					}
					if (i != 0)
					{
						word[i] = '\0';
						foregroundColor = (define_flag == 0) ? foregroundColor0 : foregroundColor1;
						textAttribute = foregroundColor | backgroundColor;
						SetConsoleTextAttribute(hStdout, textAttribute);
						printf("%s", word);
						define_flag = 0;
					}
				}
				printf("\n");
				SetConsoleTextAttribute(hStdout, 7);
				system("pause");
				return 0;
			}
