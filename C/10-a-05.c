#include <stdio.h>
#include <string.h>

int main()
{
    char s1[256];
    char s2[256];
    char s3[256];
    int len[3];
    int i;
    int t;

    printf("input a string(1):");
    fgets(s1, 256, stdin);
    len[0] = strlen(s1);
    printf("input a string(2):");
    fgets(s2, 256, stdin);
    len[1] = strlen(s2);
    printf("input a string(3):");
    fgets(s3, 256, stdin);
    len[2] = strlen(s3);

    if(len[0] >= len[1] && len[0] >= len[2]){
        printf("max:%s", s1);
    } else if(len[1] > len[0] && len[1] >= len[2]){
        printf("max:%s", s2);
    } else{
        printf("max:%s", s3);
    }

    return 0;
}