#include <stdio.h>
#define M 3 // number of use_number (=size of line)
#define N 10 // target value (=size of column)

int main()
{
    int a[M] = {2, 7, 3};
    int dp[M + 1][N + 1] = {};
    int i, j;

    dp[0][0] = 1;

    for (i = 0; i < M; i++) {
        for (j = 0; j <= N; j++) {
            if (j >= a[i]) {
                dp[i + 1][j] = (dp[i][j - a[i]] || dp[i][j]);
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    // dp table check
    printf("  ");
    for (j = 0; j <= N; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (i = 0; i <= M; i++) {
        printf("%d:", i);
        for (j = 0; j <= N; j++) {
            if (dp[i][j] == 0) {
                printf("F ");
            } else {
                printf("T ");
            }
        }
        printf("\n");
    }

    if (dp[M][N] == 1) {
        printf("Success!\n");
    } else {
        printf("Failure...\n");
    }

    return 0;
}

