#include <stdio.h>
#include <math.h>

int main()
{
    double t;
    double h = 0.4;
    double vj = 1.0;
    double vt;
    FILE *fp;

    fp = fopen("rc_result_0.4.txt", "w");

    for(int j = 0; j <= 20; j++) {
        t = h * (double) j;
        // 解析解
        vt = (-1) * exp(-t) + 2;

        // 差分解
        printf("%4.1f %10.5f %10.5f %10.5f\n", t, vj, vt, fabs(vj - vt));
        fprintf(fp, "%4.1f %10.5f %10.5f %10.5f\n", t, vj, vt, fabs(vj - vt));
        vj = 2.0 * h + (1 - h) * vj;
    }

    fclose(fp);

    return 0;
}