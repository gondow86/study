#include <stdio.h>

int main()
{
    float x;
    float y;
    int z;
    printf("Input 1st number:");
    scanf("%f", &x);
    printf("Input 2nd number:");
    scanf("%f", &y);
    z = x + y;
    printf("Result is %d\n", z);
    return 0;
}