#include <stdio.h>

int main()
{
    int c[20];
    int askii;
    int i;
    int n;

    for(i = 0; i < 20; i++){
        c[i] = 0;
    }

    for(i = 0; (askii = getchar()) != '\n' && i < 20; i++){
        c[i] = askii;
        n = i;
    }
    
    for(i = 0; i <= n/2 ; i++){

        if(c[i] != c[n - i]){
            printf("This str isn't a palindrome\n");
            return 0;
        }
    }

    printf("This str is a palindrome\n");

    return 0;
}