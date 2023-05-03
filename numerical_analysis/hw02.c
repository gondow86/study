#include <stdio.h>

int main() {
    int a = 25;
    int b = 2;
    int c = 30;
    int d;
    float p = 2.0;
    float q = 3.0;
    float x;
    float y;

    x = a / b * c; // 1
    y = a * c / b;
    if (x == y) {
        printf("x is equal to y.\n");
    } else {
        printf("x is NOT equal to y.\n");
    }
    printf("x = %d / %d * %d [=%f], y = %d * %d / %d [=%f]\n", a, b, c, x, a, c, b, y);

    x = a / p * c; // 2
    y = a * c / p;
    if (x == y) {
        printf("x is equal to y.\n");
    } else {
        printf("x is NOT equal to y.\n");
    }
    printf("x = %d / %f * %d [=%f], y = %d * %d / %f [=%f]\n", a, p, c, x, a, c, p, y);

    x = a / q * c; // 3
    y = a * c / q;
    if (x == y) {
        printf("x is equal to y.\n");
    } else {
        printf("x is NOT equal to y.\n");
    }
    printf("x = %d / %f * %d [=%f], y = %d * %d / %f [=%f]\n", a, q, c, x, a, c, q, y);

    int j = 25;
    float k = 3.0;
    printf("%f\n", j / k);
    return 0;
}