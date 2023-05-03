#include <stdio.h>

int main()
{
    int num;
    int i = 2;
    int counter;

    scanf("%d", &num);
    printf("%d is multiplication of ", num);
    if(num == 1){
        printf("%d", num);
    } else {
        while(i <= num){
            counter = 0;
            while(num % i == 0){
                num = num / i;
                counter++;
            }
            if(counter > 0){
                printf("%d^%d ", i, counter);
            }
            i++;
        }
    }
    printf("\n");

    return 0;
}