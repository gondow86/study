#include <math.h>
#include <stdio.h>

int main()
{
    int i;
    double a, b, c, f;

    a = 0.0;
    b = 10.0;

    for(i = 0; i <= 10; i++) {
        c = (a + b) / 2.0;
        f = atan(c - 1) + 0.2 * c;
        printf("%3d %20.15f\n", i, c);

        if (f < 0.0) {
            a = c;
        } else {
            b = c;
        }
    }

    return 0;
}