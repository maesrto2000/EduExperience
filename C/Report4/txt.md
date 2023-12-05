# Задание 
В массиве из 10 целых чисел сосчитать сумму элементов с чётными номерами и сумму элементов с нечётными номерами. Обнулить элементы с нечётными номерами, если их сумма меньше. В противном случае обнулить элементы с чётными номерами.
```
#include <stdio.h>
#define N 10 

int main(void)
{
	int x[N];   
	int sum_odd; 
	int sum_even; 
	int i;
	int k;
	for (i = 0; i < N; i++)
		scanf_s("%d", &x[i]);

	sum_odd = 0;
	sum_even = 0;
	for (i = 0; i < N; i++)
		if (i % 2 == 1) 
			sum_odd = sum_odd + x[i];
		else
			sum_even = sum_even + x[i];  
	if (sum_odd > sum_even)
		k = 0;
	else k = 1;
	for (i = k; i < N; i = i + 2)
		x[i] = 0;
	for (i = 0; i < N; i++)
		printf("%d ", x[i]);
	printf("\n");
	system("pause");
	return 0;
}
