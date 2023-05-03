#include <stdio.h>

int main()
{
    float a;
    float b;
    float c;
    float d;
    float ave;
    float dev_a;
    float dev_b;
    float dev_c;
    float dev_d;
    printf("Input 1st number:");
    scanf("%f", &a);
    printf("Input 2nd number:");
    scanf("%f", &b);
    printf("Input 3rd number:");
    scanf("%f", &c);
    printf("Input 4th number:");
    scanf("%f", &d);
    ave = (a + b + c + d) / 4.0;
    printf("Average: %f\n", ave);
    dev_a = a - ave;
    dev_b = b - ave;
    dev_c = c - ave;
    dev_d = d - ave;
    printf("Dispersion: %f\n", ((dev_a * dev_a) + (dev_b * dev_b) + (dev_c * dev_c) + (dev_d * dev_d)) / 4.0);
    return 0;
}