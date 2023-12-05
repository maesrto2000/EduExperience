# Задание 
Дан массив размера N. Вывести вначале его элементы с четными индексами, а затем - с нечетными
```
#include <stdio.h>
#include <stdlib.h>
int main()
{
	setlocale(0, "RU");
	int* array;
	int size, i;
	printf("введите размер массива: ");
	scanf_s("%d", &size);
	array = malloc(sizeof(int)*size); 
	for (i = 0; i < size; i++)
		scanf("%d", &array[i]);
	printf("чётные: ");
	for (i = 0; i < size; i += 2)
		printf("%d ", array[i]);
	printf("\nнечётные: ");
	for (i = 1; i < size; i += 2)
		printf("%d ", array[i]);
	system("pause");
}
