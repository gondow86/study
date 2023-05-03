#include <stdio.h>
double my_average(double);

int main()
{
    printf("%f\n", my_average(3.3));
    printf("%f\n", my_average(4.4));
    printf("%f\n", my_average(5.5));
    printf("%f\n", my_average(6.6));

    return 0;
}

double my_average(double x)
{
    static double sum = 0.0;
    static int i = 1;
    double ave;
    sum += x;
    ave = sum / i;
    i++;

    return ave;
}