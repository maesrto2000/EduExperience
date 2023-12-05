# Задание 
В каждом байте длинного целого числа N поменять местами двоичные разряды в зеркальном порядке.
```
#include <stdio.h> 
int main(void)
{
	long z;
	unsigned long y, inverted_y;
	int byte_of_y, inverted_byte;
	int i;
	inverted_y = 0;
	printf("z = ");
	scanf_s("%x", &z); 
	y = (unsigned int)z;

	while (y != 0)
	{
		byte_of_y = y & 0xFF; 
		inverted_byte = 0;
		for (i = 0;i < 8;i++) 
		{
			inverted_byte <<= 1; 
			inverted_byte += byte_of_y & 1;
			byte_of_y >>= 1; 
		}
		inverted_y <<= 8;
		inverted_y += inverted_byte;
		y >>= 8;
	}
	z = 0;
	while (inverted_y != 0)
	{
		z <<= 8;
		z += inverted_y & 0xFF; 
		inverted_y >>= 8; 
	}

	printf("result: %x\n", z);
	system("pause");
	return 0;
}
