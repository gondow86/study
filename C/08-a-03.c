#include <stdio.h>

int main()
{
    char c = 'n';

    while(c != 'y'){
        printf("Please help me!\n");
        printf("input y or n:");
        //改行文字は読み飛ばす
        scanf(" %c", &c);
        if(c == 'y'){
            printf("Thank you!\n");
            break;
        } else {
            printf("Huh?\n");
        }
    }

    return 0;
}