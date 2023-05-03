#include <stdio.h>

int main()
{
    int n;
    int i = 0;
    int total = 0;

    printf("input a positive integer:");
    scanf("%d", &n);
    while (i <= n)
    {
        total += i;
        i++;
    }
    printf("total:%d\n", total);
    
    return 0;
}