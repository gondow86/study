#include <stdio.h>

int main()
{
    char line[256];
    char *s;
    int key;

    printf("input string:");
    fgets(line, 256, stdin);
    printf("input key:");
    scanf("%d", &key);
    s = line;
    
    while(*s != '\0'){
        *s += key;
        s++;
    }
    
    printf("%s\n", line);

    return 0;
}