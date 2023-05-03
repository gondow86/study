#include <stdio.h>
#include <math.h>

int main()
{
    int i, n;
    double a, b, e, h, s, s1, s2, x, y[17000];
    double s0 = 1.718281828459045;
    a = 0.0;
    b = 1.0;
    s = 0.0;
    s1 = 0.0;
    s2 = 0.0;

    for(int m = 1; m <= 14; m++) {
        n = (int)pow(2, (double)m);
        h = (b - a) / n;
        for(i = 0; i <= n; i++) {
            x = (double)i * h + a;
            y[i] = exp(x);
        }

        for(i = 1; i <= n-1; i+=2) {
            s1 += y[i]; // 奇数だけたす
        }

        for(i = 2; i <= n-2; i+=2) {
            s2 += y[i]; // 偶数だけたす
        }
        s = (y[0] + 4.0*s1 + 2.0*s2 + y[n]) * h / 3.0; // 0とn別であとは奇数は4倍偶数は2倍
        e = fabs(s - s0);
        s1 = 0.0;
        s2 = 0.0;
        printf("%2d %20.20f %10.3e\n", m, s, e);
    }

    return 0;
}