#include <stdio.h>

int main()
{
    int x;
    printf("Input number:");
    scanf("%d", &x);
    if(x == 0){
        printf("Input number is %d.\n", x);
    } else{
        if(x % 2 == 0 && x > 0){
            printf("%d is...\nPositive even number.\n", x);
        } else if(x % 2 == 0 && x < 0){
            printf("%d is...\nNegative even number.\n", x);
        } else if(x % 2 == 1 && x > 0){
            printf("%d is...\nPositive odd number.\n", x);
        } else{
            printf("%d is...\nNegative odd number.\n", x);
        }
    }
    return 0;
}