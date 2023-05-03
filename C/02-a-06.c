#include <stdio.h>

int main()
{
    int x;
    int y;
    printf("Input 1st number:");
    scanf("%d", &x);
    printf("Input 2nd number:");
    scanf("%d", &y);
    if(x > y){
        printf("%d is larger than %d.\n", x, y);
    } else if(x < y){
        printf("%d is larger than %d.\n", y, x);
    } else{
        printf("Two numbers are equal.\n");
    }
    return 0;   
}