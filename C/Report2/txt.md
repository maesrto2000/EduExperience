# Задание 
В потоке символов сосчитать число слов, начинающихся с гласной буквы
```
#include <stdio.h>
#include <ctype.h>
#define YES 1 
#define NO 0 
int main()
{
	int c, count = 0;
	int was_delimiter = YES;
	while ((c = getchar()) != EOF)
	{
		if ((c == ' ' || c == '.' || c == ',' || c == '\n'))
		{
			//найден разделитель
			was_delimiter = YES;
		}
		else
		{
			//найдена буква
			if (was_delimiter == YES) {
				//первая буква
				c = tolower(c);
				if (c == 'a' || c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o') {
					count++; 
				}
			}
			was_delimiter = NO;
		}
		
	}
	printf("number of words = %d\n", count);
	system("pause");
	return 0;
}
