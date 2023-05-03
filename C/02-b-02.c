#include <stdio.h>

int main()
{
    int a;
    int b;
    float c;
    float d;
    printf("input a:");
    scanf("%d", &a);
    printf("input b:");
    scanf("%d", &b);
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d × %d = %d\n", a, b, a * b);
    c = a;
    d = b;
    printf("%d ÷ %d = %f\n", a, b, c / d);
    return 0;
}