#include <stdio.h>
#include <math.h>

int main()
{
    int i, n;
    double t, tt, h, v_ana, v_euler, v_runge, u_euler, u_runge, tmp_euler, tmp_runge;
    double k, k1, k2, k3, k4, m, m1, m2, m3, m4, v1, v2, v3, u1, u2, u3;

    tt = 20.0;
    h = 0.25;
    n = (int) (tt / h);
    v_euler = 1.0;
    u_euler = 0.0;
    v_runge = 1.0;
    u_runge = 0.0;

    for (i = 0; i <= n; i++) {
        t = i * h;
        v_ana = (3.0/2.0) * exp(-t) + (3.0/2.0) * t * exp(-t) - (1.0/2.0) * cos(t);
        printf("%5.2f %10.5f %10.5f %10.5f %11.6f %11.6f\n", t, v_ana, v_euler, v_runge, fabs(v_ana - v_euler), fabs(v_ana - v_runge));

        // euler
        tmp_euler = u_euler;
        u_euler = h * (-2 * u_euler - v_euler + sin(t)) + u_euler;
        v_euler = tmp_euler * h + v_euler;

        // runge-kutta
        k1 = -2.0 * u_runge - v_runge + sin(t);
        m1 = u_runge;

        u1 = k1 * h / 2.0 + u_runge;
        v1 = m1 * h / 2.0 + v_runge;
        k2 = -2.0 * u1 - v1 + sin(t);
        m2 = u1;

        u2 = k2 * h / 2.0 + u_runge;
        v2 = m2 * h / 2.0 + v_runge;
        k3 = -2.0 * u2 - v2 + sin(t);
        m3 = u2;

        u3 = k3 * h + u_runge;
        v3 = m3 * h + v_runge;
        k4 = -2.0 * u3 - v3 + sin(t);
        m4 = u3;

        k = (k1 + 2.0 * (k2 + k3) + k4) / 6.0;
        m = (m1 + 2.0 * (m2 + m3) + m4) / 6.0;

        u_runge = k * h + u_runge;
        v_runge = m * h + v_runge;
    }

    return 0;
}