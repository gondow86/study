#include <stdio.h>

int main()
{
    int x;
    printf("Please input number:");
    scanf("%d", &x);
    if(x >= 1 && x <= 100){
        printf("Sum 1 - %d is: %d\n", x, ((x * (x + 1)) / 2));
    } else{
        printf("Error: input range is 1 to 100\n");
    }
    return 0;
}