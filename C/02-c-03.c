#include <stdio.h>

int main()
{
    int x;
    printf("input an integer:");
    scanf("%d", &x);
    if(x % 2 == 0){
        if(x % 3 == 0){
            if(x % 5 == 0){
                printf("%d is divisible by 2, 3 and 5.\n", x);
            } else{
                printf("%d is divisible by 2 and 3 but not divisible by 5.\n", x);
            }
        } else{
            if(x % 5 == 0){
                printf("%d is divisible by 2 and 5 but not divisible by 3.\n", x);
            } else{
                printf("%d is divisible by 2 but not divisible by 3 nor 5.\n", x);
            }
        }
    } else{
        if(x % 3 == 0){
            if(x % 5 == 0){
                printf("%d is divisible by 3 and 5 but not divisible by 2.\n", x);
            } else{
                printf("%d is divisible by 3 but not divisible by 2 nor 5.\n", x);
            }
        } else{
            if(x % 5 == 0){
                printf("%d is divisible by 5 but not divisible by 2 nor 3.\n", x);
            } else{
                printf("%d is not divisible by 2, 3 nor 5.\n", x);
            }
        }
    }
    return 0;
}