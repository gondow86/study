#include <stdio.h>

void swap(float *x, float *y)
{
    float t;
    t = *x;
    *x = *y;
    *y = t;
    return;
}
int main()
{
    float a;
    float b;
    printf("Input 1st number:");
    scanf("%f", &a);
    printf("Input 2nd number:");
    scanf("%f", &b); 
    swap(&a, &b);
    printf("Swapped 1st: %f, 2nd: %f\n", a, b);
    return 0;
}