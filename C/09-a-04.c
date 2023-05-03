#include <stdio.h>

int count(char c[], int n)
{
    int counter = 0;
    int i;

    printf("input 10 characters:");

    for(i = 0; i < n; i++){
        c[i] = getchar();
        switch (c[i]){
            case 'a':
            case 'i':
            case 'u':
            case 'e':
            case 'o':
                counter++;
                break;
            
            default:
                break;
        }
    }

    return counter;
}

int main()
{
    char c[10];
    int n = 10;
    int counter;
    
    counter = count(c, n);
    printf("count:%d\n", counter);

    return 0;
}