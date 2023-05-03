#include <stdio.h>

int main()
{
    int decimal;
    int binary[32] = {0};
    int quotient;
    int count;
    int i;

    printf("input a decimal number:");
    scanf("%d", &decimal);
    for(i = 0; i < 32; i++){
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        if(binary[i] == 1){
            count = i;
        }
    }
    printf("binary number:");
    for(i = count; i >= 0; i--){
        if(i == 0){
            printf("%d\n", binary[i]);
        } else{
            printf("%d", binary[i]);
        }
    }

    return 0;
}