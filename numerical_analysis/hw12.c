#include <stdio.h>
#include <math.h>
# define N 3

int main()
{
    int i, j, k, d;
    float alpha, bi, max, tmp;
    float a[N][N] = {{0.001, 2.0, -1.0},
                      {1.0, -1.0, 1.0},
                      {4.0, 2.0, 5.0}};
    float b[N] = {11.002, -4.0, 13.0};
    float x[N] = {0.0, 0.0, 0.0};

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
        // ピボットの交換
        d = k;
        max = fabs(a[k][k]);
        for (i = k + 1; i < N; i++) {
            if (fabs(a[i][k]) > max) {
                d = i;
                max = fabs(a[i][k]);
            }
        }
        for (j = k; j < N; j++) {
            tmp = a[k][j];
            a[k][j] = a[d][j];
            a[d][j] = tmp;
        }
        tmp = b[k];
        b[k] = b[d];
        b[d] = tmp;

        printf("\n** Forward Elimination (k=%d)**", k);
        printf("Ab = \n");

        for (i = 0; i < N; i++) {
            printf(" |");
            for (j = 0; j < N; j++) {
                printf("%8.3f", a[i][j]);
            }
            printf(" ||%8.3f|\n", b[i]);
        }

        // 前進消去
        for (i = k + 1; i < N; i++) {
            alpha = a[i][k] / a[k][k];
            printf("pivot: %f, alpha: %f\n", a[k][k], alpha);
            for (j = k; j < N; j++) {
                a[i][j] -= alpha * a[k][j];
            }
            b[i] -= alpha * b[k];
        }
    }

    // 後退代入
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
        printf(" |%15.7f|\n", x[j]);
    }
    printf("\n");

    return 0;
}