#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>;
#include <time.h>;
int main(void)
{

	int** a;
	int** b;
	int**c;
	int i = 0, j = 0, r, N;
	printf("Введите размер массива");
	scanf("%d", &N);
	a = (int**)malloc(N * sizeof(int));
	b = (int**)malloc(N * sizeof(int));
	c = (int**)malloc(N * sizeof(int));
	long int  elem_c;
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	
	for (i=0;i < N;i++)
	{
		for (j = 0; j < N;j++)
		{
			a[i][j] = rand() % 100 + 1;
			  // заполняем массив случайными числами
			
			printf("%ld ", a[i][j]);
		}
		
	}
	printf("\n");
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < N)
	{
		while (j < N)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
			printf("%ld ", b[i][j]);
		}
		i++;
	}
	printf("\n");
	clock_t start = clock();
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			elem_c = 0;
			for (r = 0; r < N; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	printf("%ld ", c[N - 1][N - 1]);
	printf("\n");

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f", time_spent);
	return(0);
}