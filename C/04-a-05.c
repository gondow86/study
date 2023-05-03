#include <stdio.h>

void hundred1(int x)
{
    x = 100;
    return;   
}

void hundred2(int *y)
{
    *y = 100;
    return;
}

int main()
{
    int a = 500;
    int b = 500;
    printf("before: a = %d, b = %d\n", a, b);
    hundred1(a);
    hundred2(&b);
    printf("after: a = %d, b = %d\n", a, b);
    return 0;
}