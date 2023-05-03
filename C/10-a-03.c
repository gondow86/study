#include <stdio.h>
#include <string.h>

int main()
{
    char s1[256];
    char s2[256];
    int res;

    printf("input first string:");
    fgets(s1, 256, stdin);
    printf("input second string:");
    fgets(s2, 256, stdin);
    res = strcmp(s1, s2);

    if(res == 0){
        printf("same.\n");
    } else{
        printf("different.\n");
    }

    return 0;
}