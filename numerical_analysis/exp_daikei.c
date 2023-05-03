#include <stdio.h>
#include <math.h>

int main()
{
    double y1;
    double y_new = 0.0;
    double error = 0.0;
    double a = 0.0;
    double b = 1.0;
    int n = 1;
    double y_ana = 1.718281828459045;
    double h = b - a;
    double y0 = (exp(a) + exp(b))*h / 2.0;

    for(int m = 1; m <= 14; m++) {
        n *= 2;
        h /= 2.0;
        // 新たな分割点の関数値の総和
        y1 = 0.0;
        for(int i = 1; i < n; i += 2) {
            y1 += exp(a + i * h);
        }
        y_new = y0 / 2.0 + y1 * h;
        error = fabs(y_new - y_ana);
        y0 = y_new;

        printf("%2d %20.15f %10.3e\n", m, y0, error);
    }

    return 0;
}