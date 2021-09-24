#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>;
#include <time.h>;
void qs(int* items, int left, int right) //����� �������: qs(items, 0, count-1);
{
int i, j;
int x, y;

i = left; j = right;
/* ����� ���������� */
x = items[(left + right) / 2];
do {
    while ((items[i] < x) && (i < right)) i++;
    while ((x < items[j]) && (j > left)) j--;
    if (i <= j) {
        y = items[i];
        items[i] = items[j];
        items[j] = y;
        i++; j--;
    }
} while (i <= j);
if (left < j) qs(items, left, j);
if (i < right) qs(items, i, right);
}
    void shell_sort(int* array, int size) {
        for (int s = size / 2; s > 0; s /= 2) {
            for (int i = 0; i < size; i++) {
                for (int j = i + s; j < size; j += s) {
                    if (array[i] > array[j]) {
                        int temp = array[j];
                        array[j] = array[i];
                        array[i] = temp;
                    }
                }
            }
        }
    }
    void DecreasingSort(int n, int mass[])
    {
        int new, location;
        for (int i = 1; i < n; i++)
        {
            new = mass[i];
            location = i - 1;
            while (location >= 0 && mass[location] < new)
           {
                mass[location + 1] = mass[location];
                location = location - 1;
            }
            mass[location + 1] = new;
        }
    }
    void AscendingSort(int n, int mass[])
    {
        int new, location;
        for (int i = 1; i < n; i++)
        {
            new = mass[i];
            location = i - 1;
            while (location >= 0 && mass[location] > new)
            {
                mass[location + 1] = mass[location];
                location = location - 1;
            }
            mass[location + 1] = new;
        }
    }
    int comp(const void* x1, const void* x2)   // ������� ��������� ��������� �������
    {
        return (*(int*)x1 - *(int*)x2);              // ���� ��������� ��������� ����� 0, �� ����� �����, < 0: x1 < x2; > 0: x1 > x2
    }
    main() {
        int* a;
        int N,k;
       
        printf("������� ������ �������: ");
        scanf("%d", &N);
        a = (int*)malloc(N * sizeof(int));
        srand(time(NULL));
        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % 10000;
            
        }
      
        
        DecreasingSort(N, a);
        AscendingSort(N / 2, a);
        printf("\n");
        clock_t start = clock();
        qsort(a, N, sizeof(int), (int(*) (const void*, const void*)) comp);
       clock_t end = clock();
      
       
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
       printf("���������� ���������� ������ %f", time_spent);

    
    }

    