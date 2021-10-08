#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void obhod(int num, int* visits, int** matrix, int len)//����� ����� � �������
{
	visits[num] = 1;
	printf("%d ", num);
	for (int i = 0; i < len; i++) {
		if (matrix[num][i] == 1 && visits[i] == 0) {
			obhod(i, visits, matrix, len);
		}
	}
}

int main(void)
{
	setlocale(LC_ALL, "Rus");
	int** a;
	int N;
	printf("������� N: ");
	scanf("%d", &N);
	a = (int**)malloc(N * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		int* b = (int*)malloc(N * sizeof(int));
		for (int j = 0; j < N; j++) {
			b[j] = 0;
		}
		a[i] = b;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				int num = rand() % 2;
				a[i][j] = num;
				a[j][i] = num;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	int len = N;
	int* visits = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		visits[i] = 0;
	}
	printf("������� �������: ");
	scanf("%d", &N);
	obhod(N, visits, a, len);
	
}

