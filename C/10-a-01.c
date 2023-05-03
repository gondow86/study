#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char line[256];
    char *p;

    if(fgets(line, 256, stdin) != NULL){
        p = strchr(line, '\n');
        if(p != NULL){
            *p = '\0';
        }
    }
    printf("%s", line);

    return 0;
}