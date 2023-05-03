#include <stdio.h>
#include <math.h>

int main()
{
    int i, m, n;
    double a, b, h, y, y0;

    a = 0.0;
    b = 2.0;
    y0 = sin(2.0) - sin(0.0);

    for(m = 1; m <= 10; m++) {
        n = (int)pow(2.0, (double)m);

        h = (b - a) / n;
        y = 0.0;
        y = 0.5 * (cos(a) + cos(b)) * h;

        for(i = 1; i < n; i++){
            y += cos(a + i * h) * h;
        }

        printf("%2d %4d %20.15f %12.3e\n", m, n, y, fabs(y - y0));
    }

    return 0;
}