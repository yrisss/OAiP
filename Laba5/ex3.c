#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main()
{
	setlocale (LC_ALL, "");
    srand(time(0));
    int n;
    int i, j, k, max, temp, temp1 = -1, stop = 0;
    printf("Введите размерность матрицы: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Сгенерированная матрица: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10;
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n && stop == 0; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            max = j;
            for (k = j + 1; k < n; k++)
            {
                if (a[i][max] < a[i][k])
                {
                    temp1 = i;
                    max = k;
                    stop = 1;
                }
            }
            if (max != j)
            {
                temp = a[i][max];
                a[i][max] = a[i][j];
                a[i][j] = temp;
            }
        }
    }
    if (temp1 != -1)
    {
        printf("Не все строки упорядоченны по убыванию\n");
        printf("Номер первой строки не упорядочен по убыванию: %d\n", temp1 + 1);
    }
    else
        printf("Все строки упорядоченны по убыванию\n");
    printf("Конечная матрица: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
