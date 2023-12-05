# Задание 
В символьной строке удалить все слова, начинающиеся с гласной буквы.
```
#include <stdio.h> 
#include <cstdlib>
#define YES 1 
#define NO 0 
#define MAXLINE 1000 

void process_line(char buffer[]);

int main(void)
{
	char line[MAXLINE];

	gets_s(line);
	process_line(line);
	puts(line);
	system("pause");
	return 0;
}

void process_line(char buffer[])
{
	char c; 
	int prev_c; 
	int flag;  
	int found;  		  
	int i;		 
	int pos; 	  
	int start;  
	int j; 
	flag = NO;
	found = NO;
	prev_c = ' ';
	start = 0;
	i = 0;
	pos = 0;
 
	do
	{
		c = buffer[i];  
		if (c == ' ' || c == '.' || c == ',' ||
			c == '\n' || c == '\0')
		{  
			if (flag == YES)
			{  
				if (found == NO)
				{  
					for (j = start; j < i; j++)
						buffer[pos++] = buffer[j];
				}
			}
			flag = NO;
			buffer[pos++] = c;
		}
		else
		{  
			if (flag == NO) 
start = i;
			buffer[start];
			if (buffer[start] == 'a' || buffer[start] == 'e' || buffer[start] == 'i' || buffer[start] == 'u' || buffer[start] == 'y' || buffer[start] =='o')
				found = YES;
			else
				found = NO;

			flag = YES;
		}

		prev_c = c;
		i++;
	} while (c != '\0');
}
