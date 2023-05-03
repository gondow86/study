#include <stdio.h>

int main()
{
    int n;
    int i;
    printf("input an integer:");
    scanf("%d", &n);
    for (i = 0; i < n - 1; i++){
        printf("*");
    }
    printf("*\n");
    return 0;
}