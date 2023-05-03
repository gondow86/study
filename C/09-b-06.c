#include <stdio.h>

int main()
{
    int a[32] = {};
    unsigned int i;
    int j;
    int mod;
    int index;

    printf("word = 0x");
    scanf("%x", &i);
    for(j = 0; j < 32; j++){
        mod = i % 2;
        a[31 - j] = mod;
        i = i / 2;
        if(i == 0){
            break;
        }
    }
    for(j = 0; j < 32; j++){
        if(a[31 - j] == 1){
            printf("bit index = %d\n", j);
            break;
        }
    }

    return 0;
}