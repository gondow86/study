#include <stdio.h>
#include <math.h>

int main()
{
    int j;
    double h, t, y0, y_runge_kutta, y_heun, y_eular;
    double y1_rk, y1_h, y2, y3, k1_rk, k1_h, k1_e, k2_rk, k2_h, k3, k4;
    double error_rk, error_h, error_e;

    h = 0.2;
    y0 = 1.0;
    y_runge_kutta = y0;
    y_heun = y0;
    y_eular = y0;

    for(j = 0; j <= 25; j++) {
        t = h * (double)j;
        error_rk = fabs(exp(t) - y_runge_kutta);
        error_h = fabs(exp(t) - y_heun);
        error_e = fabs(exp(t) - y_eular);

        printf("%5f %10.5f %10.5f %10.5f %10.5f %11.6f %11.6f %11.6f\n", t, exp(t), y_runge_kutta, y_heun, y_eular, error_rk, error_h, error_e);

        k1_rk = y_runge_kutta;
        y1_rk = k1_rk * h / 2.0 + y_runge_kutta;
        k2_rk = y1_rk;
        y2 = k2_rk * h / 2.0 + y_runge_kutta;
        k3 = y2;
        y3 = k3 * h + y_runge_kutta;
        k4 = y3;
        y_runge_kutta = (k1_rk + 2.0 * k2_rk + 2.0 * k3 + k4) * h / 6.0 + y_runge_kutta;

        k1_h= y_heun;
        y1_h = k1_h * h + y_heun;
        k2_h = y1_h;
        y_heun = (k1_h + k2_h) * h / 2.0 + y_heun;

        k1_e = y_eular;
        y_eular = k1_e * h + y_eular;
    }

    return 0;

}