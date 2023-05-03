#include <stdio.h>
#include <string.h>

int main()
{
    char s1[256];
    char s2[256];

    fgets(s2, 256, stdin);
    strncpy(s1, s2, 3);
    s1[3] = '\0';
    printf("%s\n", s1);

    return 0;
}