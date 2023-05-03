#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    double df, h, f, x;

    h = 0.1;
    x = 5.0;

    for(i = 0; i <= 10; i++) {
        printf("%3d %20.15f\n", i, x);
        f = atan(x - 1) + 0.2 * x;
        df = (atan(x + h - 1) + 0.2 * (x + h) - atan(x - 1) - 0.2 * x) / h;
        x = x - f / df;
        // x = x - h * (atan(x - 1) + 0.2*x) / (atan(x + h - 1) + 0.2*(x + h) - atan(x - 1) - 0.2 * x);
    }

    return 0;
}