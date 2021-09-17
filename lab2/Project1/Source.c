#include <stdio.h>
#include <stdlib.h>;
#include <time.h>;
int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	int i = 0, j = 0, r;
	long int a[400][400], b[400][400], c[400][400], elem_c;
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	clock_t start = clock();
	while (i < 400)
	{
		while (j < 400)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
			printf("%ld ", a[i][j]);
		}
		i++;
	}
	printf("\n");
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < 400)
	{
		while (j < 400)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
			printf("%ld ", b[i][j]);
		}
		i++;
	}
	printf("\n");
	for (i = 0; i < 400; i++)
	{
		for (j = 0; j <400; j++)
		{
			elem_c = 0;
			for (r = 0; r < 400; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	printf("%ld ", c[399][399]);
	printf("\n");

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f", time_spent);
	return(0);
}