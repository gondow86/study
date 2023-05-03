#include <stdio.h>
#include <stdlib.h>

void print_sequence(int i)
{
    if (i == 1){
        printf("%d ", i);
        return;
    }
    print_sequence(i - 1);
    printf("%d ", i);
    return;
}

int main()
{
    int i;

    printf("input an integer:");
    scanf("%d", &i);
    print_sequence(i);

    return 0;
}