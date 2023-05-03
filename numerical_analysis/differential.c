#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    double df, f, x;

    x = 2.5;

    for(i = 0; i <= 10; i++) {
        printf("%3d %20.15f\n", i, x);
        f = atan(x - 1) + 0.2 * x;
        df = 1 / (1 + (x - 1) * (x - 1)) + 0.2;
        // x = x - (atan(x-1) + 0.2*x) / (1.2 + 0.2*(x - 1) * (x - 1)) / (1 + (x - 1) * (x - 1));
        x = x - (f / df);
    }

    return 0;
}