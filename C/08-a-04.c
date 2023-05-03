#include <stdio.h>

int main()
{
    int i = 0;
    int num;
    int sum = 0;

    while(i < 5){
        printf("input a positive integer:");
        scanf("%d", &num);
        if(num < 0){
            printf("Error:invalid input\n");
            continue;
        }
        if(num == 0){
            break;
        }
        sum += num;
        i++;
    }
    printf("total:%d\n", sum);

    return 0;
}