#include <stdio.h>
# define N 3

int main()
{
    int i, j, k;
    double alpha, bi;
    double a[N][N] = {{5.0, 6.0, -3.0},
                      {2.0, 2.0, 1.0},
                      {1.0, 1.0, -1.0}};
    double b[N] = {-8.0, 0.0, -3.0};
    double x[N] = {0.0, 0.0, 0.0};

    printf("\n** Extended Coefficient Matrix **\n");
    printf("Ab = \n");

    for (i = 0; i < N; i++) {
        printf(" |");
        for (j = 0; j < N; j++) {
            printf("%8.3f", a[i][j]);
        }
        printf(" ||%8.3f|\n", b[i]);
    }

    for (k = 0; k < N - 1; k++) {
        for (i = k + 1; i < N; i++) {
            alpha = a[i][k] / a[k][k];
            for (j = k; j < N; j++) {
                a[i][j] -= alpha * a[k][j];
            }
            b[i] -= alpha * b[k];
        }
    }

    printf("\n** Forward Elimination **");
    printf("Ab = \n");

    for (i = 0; i < N; i++) {
        printf(" |");
        for (j = 0; j < N; j++) {
            printf("%8.3f", a[i][j]);
        }
        printf(" ||%8.3f|\n", b[i]);
    }


    for (i = N - 1; i >= 0; i--) {
        bi = b[i];
        for (k = i + 1; k < N; k++) {
            bi -= a[i][k] * x[k];
        }
        x[i] = bi / a[i][i];
    }

    printf("\n** Solution **\n");
    printf("x = \n");
    for (j = 0; j < N; j++) {
        printf(" |%8.3f|\n", x[j]);
    }
    printf("\n");

    return 0;
}