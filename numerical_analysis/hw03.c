#include <stdio.h>
#define N 8192

int main() {
    double x = 1.0 / N;
    double sum = 0;

    for (int i = 0; i < N; i++) {
        sum += x;
    }

    if (sum == 1.0) {
        printf("N: %d, sum: %f, result: True\n", N, sum);
    } else {
        printf("N: %d, sum: %f, result: False\n", N, sum);
    }


    return 0;
}