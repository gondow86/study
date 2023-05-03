#include <stdio.h>

int main()
{
    int a;
    int *p;

    printf("input an integer:");
    scanf("%d", &a);
    p = &a;
    printf("address of a is %p\n", p);
    printf("value of a is %d\n", *p);

    return 0;
}