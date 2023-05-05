#include <stdio.h>
#include <math.h>

#define N 3
#define EPS 1e-5

int main()
{
    double A[N][N] = {{5, -4, -1}, {4, 1, -2}, {3, 1, -5}}; //матрица коэффицентов
    double b[N] = {-2, 8, 10}; // вектор свободных членов
    double x[N], x0[N], C[N][N], d[N]; //решение системы, предыдущее приближение, итерационные формы исходных данных
    int i, j, k; // счетчики циклов
    int iter; // количество итераций;
    int count_eps;

    // Проверка и перестановка диагональных элементов
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (fabs(A[i][i]) < fabs(A[j][i])) {
                for (k = 0; k < N; k++) {
                    double temp = A[i][k];
                    A[i][k] = A[j][k];
                    A[j][k] = temp;
                }
                double temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    // Вычисление матрицы C и вектора d
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == j) {
                C[i][j] = 0;
            } else {
                C[i][j] = -A[i][j] / A[i][i];
            }
        }
        d[i] = b[i] / A[i][i];
        x[i] = d[i];
    }

    // Итерационный процесс
    iter = 0;
    do {
        iter++;
        for (i = 0; i < N; i++) {
            x0[i] = x[i];
        }
        for (i = 0; i < N; i++) {
            x[i] = d[i];
            for (j = 0; j < N; j++) {
                x[i] += C[i][j] * x0[j];
            }
        }
        count_eps = 0;
        for (i = 0; i < N; i++) {
            if (fabs(x[i] - x0[i]) < EPS) {
                count_eps++;
            }
        }
    } while (count_eps != N && iter<= 10);

    // Вывод результатов
    printf("Решение системы:\n");
    for (i = 0; i < N; i++) {
        printf("x%d = %f\n", i + 1, x[i]);
    }

    return 0;
}