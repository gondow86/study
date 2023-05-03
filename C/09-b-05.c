#include <stdio.h>

int main()
{
    int a[8] = {};
    int i;
    int askii;
    int mod;

    askii = getchar();
    for(i = 0; i < 8; i++){
        mod = askii % 2;
        a[7 - i] = mod;
        askii = askii / 2;
        if(askii == 0){
            break;
        }
    }
    for(i = 0; i < 8; i++){
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}