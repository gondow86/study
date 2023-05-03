#include <stdio.h>

int main()
{
    int a[5];
    int i;
    printf("input 5 numbers:");
    for(i = 0; i < 5; i++){
        scanf("%d", &a[i]);
    }
    printf("%d\n", a[4] * 10000 + a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0]);
    return 0;
}