#include <stdio.h>

int main()
{
    int i = 0;
    int *ip;
    char c = 0;
    char *cp;

    ip = &i;
    cp = &c;

    printf("ip:   %p\n", ip);
    ++ip;
    printf("++ip: %p\n", ip);
    printf("cp:   %p\n", cp);
    ++cp;
    printf("++cp  %p\n", cp);

    return 0;
}