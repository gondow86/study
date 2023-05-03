#include <stdio.h>
#include <string.h>

int mystrlen(char *s)
{
    int counter = 0;
    
    while(*s != '\0'){
        counter++;
        s++;
    }

    return counter;
}

int main()
{
    char line[256];
    int mylen;
    int len;

    fgets(line, 256, stdin);
    mylen = mystrlen(line);
    len = strlen(line);
    printf("Length(mystrlen):%d\n", mylen);
    printf("Length(strlen):%d\n", len);

    return 0;
}