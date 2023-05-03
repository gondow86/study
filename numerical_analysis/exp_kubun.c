#include <stdio.h>
#include <math.h>

int main()
{
    int i, m, n;
    double a, b, h, y, y_ana;

    a = 0.0;
    b = 1.0;

    y_ana = 1.718281828459045;

    for(m = 1; m <= 14; m++) {
        n = (int)pow(2.0, (double)m);

        h = (b - a) / n;
        y = 0.0;

        for(i = 0; i < n; i++){
            y += exp(a + i * h) * h;
        }

    printf("%2d %20.15f %10.3e\n", m, y, fabs(y - y_ana));
    }

    return 0;
}