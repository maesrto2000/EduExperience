# Задание 
В символьной строке удалить самое длинное слово
```
# include <stdio.h>
#define LEN 1000
void main(void)
{
	char line[LEN];
	int counter = 0;
	int max = 0;
	char* ptr;
	char* startPtr;
	gets(line);
	ptr = line;
	startPtr = line;
	while (*ptr != '\0') 
	{
		if ((*ptr != ' ') && (*ptr != '.') && (*ptr != ','))
		{
			counter++;
			if (counter > max)
			{
				max = counter;
				startPtr = (ptr - max + 1);
			}
		}
		else
			counter = 0;
		ptr++;
	}

	while (*startPtr != '\0') 
	{
		*startPtr = *(startPtr + max);
		startPtr++;
	}

	puts(line);
}
