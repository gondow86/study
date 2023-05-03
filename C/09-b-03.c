#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF){
        if(c != '\n'){
            printf("%d\n", c);
        }
    }
    
    return 0;
}