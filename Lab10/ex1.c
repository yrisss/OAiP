#include <stdio.h>

#define N 3 //Кол-во уравнений

int main()
{
    double A[N][N+1] = {{1.6, 0.12, 0.57, 0.18},
                        {0.38, 0.25, -0.54, 0.63},
                        {0.28, 0.46, -1.12, 0.88}};

    int i, j, k;
    double c, m;

    // прямой ход
    for (i = 0; i < N-1; i++) {
        for (j = i+1; j < N; j++) {
            c = A[j][i] / A[i][i];
            for (k = i; k < N+1; k++) {
                A[j][k] -= c * A[i][k];
            }
        }
    }

    // обратный ход
    double x[N];
    for (i = N-1; i >= 0; i--) {
        x[i] = A[i][N] / A[i][i];
        for (j = i-1; j >= 0; j--) {
            A[j][N] -= A[j][i] * x[i];
            A[j][i] = 0;
        }
    }

    printf("x1 = %.2f\nx2 = %.2f\nx3 = %.2f\n", x[0], x[1], x[2]);

    return 0;
}