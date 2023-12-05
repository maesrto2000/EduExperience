# Задание 1
Вычислить сумму первых N элементов ряда:    
![image](https://github.com/maesrto2000/EduExperience/assets/97037894/06dc578f-e6b2-4dab-9322-8cf3a914ae18)
```
#include <stdio.h> 

int main(void)
{
	float x, s = 1, q = 1; 
	int n, k;
	printf("x=");
	scanf("%f", &x);
	printf("n=");
	scanf("%d", &n);
	for (k = 1;k < n; k++)
	{
		q *= x / (float)k;
		s += q;
	}
	printf("s=%.4f", s);
	return 0;
}

