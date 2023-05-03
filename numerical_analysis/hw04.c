#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    double a, b, c, d, e, f, true;

    true = 0.7034674;
    a = 5.0;
    b = 0.0;
    e = 5.0e-6;

    for (i = 1; i <= 1000; i++) {
        c = (a + b) / 2.0;
        d = fabs(c - true);
        printf("%d %.8f %e \n", i, c, d);
        f = exp(-c) - c * c;
        if (f < 0) {
            a = c;
        } else if (f > 0) {
            b = c;
        } else {
            break;
        }

        if (d < e) {
            break;
        }
    }


    return 0;
}