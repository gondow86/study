#include <stdio.h>
#include <math.h>
#include <string.h>

#define M 4
#define N 10

int main()
{
    // double data[2][N] = {{-1.0, 0.0, 1.0, 2.0},
    //                     {0.0, -1.0, 0.0, 1.0}};
    double data[2][N] = {{-2.0, -1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5, 2.0, 2.5},
                        {-3.0, -6.0, -2.0, 4.0, 9.0, 6.0, 5.0, 1.0, 0.0, 3.0}};

    int d, i, j, k;
    double alpha, bi, max, dummy;
    double a[M+1][M+1], b[M+1], x[M+1];

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(x, 0, sizeof(x));

    // Extended Coefficient Matrix
    for (i = 0; i <= M; i++) {
        for (j = 0; j <= M; j++) {
            for (k = 0; k < N; k++) {
                a[i][j] += pow(data[0][k], ((i + j) * 1.0));
            }
        }
    }

    for (i = 0; i <= M; i++) {
        for (k = 0; k < N; k++) {
            b[i] += pow(data[0][k], (i * 1.0)) * data[1][k];
        }
    }

    // Forward Elimination
    for (k = 0; k <= M - 1; k++) {
        d = k;
        max = fabs(a[k][k]);

        for (i = k + 1; i <= M; i++) {
            if (fabs(a[i][k]) > max) {
                d = i;
                max = fabs(a[i][k]);
            }
        }

        for (j = k; j <= M; j++) {
            dummy = a[k][j];
            a[k][j] = a[d][j];
            a[d][j] = dummy;
        }

        dummy = b[k];
        b[k] = b[d];
        b[d] = dummy;

        for (i = k + 1; i <= M; i++) {
            alpha = a[i][k] / a[k][k];

            for (j = k; j <= M; j++) {
                a[i][j] -= alpha * a[k][j];
            }
            b[i] -= alpha * b[k];
        }
    }

    // Backward Substitution
    for (i = M; i >= 0; i--) {
        bi = b[i];

        for (k = i + 1; k <= M; k++) {
            bi -= a[i][k] * x[k];
        }
        x[i] = bi / a[i][i];
    }

    printf("\n Solution x = \n");

    for (j = 0; j <= M; j++) {
        printf("     |%8.3f | \n", x[j]);
    }
    printf("\n");
    printf("b = (%6.2f) + (%6.2f)*a + (%6.2f)*a^2 \n", x[0], x[1], x[2]);

    return 0;
}