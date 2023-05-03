#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

#define M 4 // n-th degree
#define N 10 // number of data

int main()
{
    double data[2][N] = {{-2.0, -1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5, 2.0, 2.5},
                        {-3.0, -6.0, -2.0, 4.0, 9.0, 6.0, 5.0, 1.0, 0.0, 3.0}};

    int d, i, j, k;
    double alpha, bi, max, tmp;
    double a[M+1][M+1], b[M+1], x[M+1];

    struct timeval stime, etime;
    double sec;
    gettimeofday(&stime, NULL);

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
            tmp = a[k][j];
            a[k][j] = a[d][j];
            a[d][j] = tmp;
        }

        tmp = b[k];
        b[k] = b[d];
        b[d] = tmp;

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
    gettimeofday(&etime, NULL);
	sec = (etime.tv_sec - stime.tv_sec) +
	    (etime.tv_usec - stime.tv_usec) / 1000000.0;
	printf("Elapsed Time %.6f [sec] \n", sec);

    for (j = 0; j <= M; j++) {
        printf("x%d = %.3f  \n", j, x[j]);
    }
    printf("\n");
    printf("b = (%.2f) + (%.2f)*a + (%.2f)*a^2 + (%.2f)*a^3 + (%.2f)*a^4 \n", x[0], x[1], x[2], x[3], x[4]);

    return 0;
}