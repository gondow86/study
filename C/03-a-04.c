#include <stdio.h>

int main()
{
    int input;
    int input_copy;
    int i;
    printf("input an integer:");
    scanf("%d", &input);
    input_copy = input;
    for(i = 0; input != 0; i++){
        input = input / 10;
    }
    printf("%d is a %d digits number\n", input_copy, i);
    return 0;
}