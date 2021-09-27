#include <stdio.h>
#include <stdlib.h>;
#include <time.h>;
int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	
	int i = 0, j = 0, r;
	int a[120][120], b[120][120], c[120][120], elem_c;
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	
	while (i< 120)
	{
		while (j< 120)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
			printf("%d", a[i][j]);
		}
		i++;
	}
	printf("\n");
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i< 120)
	{
		while (j< 120)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
			printf("%d", &b[i][j]);
		}
		i++;
	}
	printf("\n");
	clock_t start = clock();
	for (i = 0; i < 120; i++)
	{
		for (j = 0; j< 120; j++)
		{
			elem_c = 0;
			for (r = 0; r < 120; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	printf("%d", c[119][119]);
	printf("\n");
	
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f",time_spent);
	return(0);
}