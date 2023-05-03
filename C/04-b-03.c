#include <stdio.h>

void mytoupper(char *c)
{
    if(*c >= 'a' && *c <= 'z'){
        *c = *c - 'a' + 'A';
    }
    return;
}
int main()
{
    char x;
    printf("Input character:");
    scanf("%c", &x);
    mytoupper(&x);
    printf("Output character:%c\n", x);

    return 0;
}