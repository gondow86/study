#include <stdio.h>
#define MAX_LEN 256

char *mystrcat(char *s1, char *s2)
{
    char *str;
    str = s1;
    while(*s1 != '\0'){
        s1++;
    }

    while(*s2 != '\0'){
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';

    return str;
}

int main()
{
    char str1[MAX_LEN] = "abc", str2[] = "def";

    mystrcat(str1, str2);
    printf("%s\n", str1);

    return 0;
}