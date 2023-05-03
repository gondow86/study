#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char num[12];
    char name[10];
    char *p;

    printf("Input student number:");
    if(fgets(num, 10, stdin) != NULL){
        p = strrchr(num, '\n');
        if(p != NULL){
            *p = '\0';
        }
    }
    printf("Input name:");
    if(fgets(name, 10, stdin) != NULL){
        p = strrchr(name, '\n');
        if(p != NULL){
            *p = '\0';
        }
    }

    fp = fopen("11-a-01.txt", "w");
    if(fp == NULL){
        perror("11-a-01.txt");
        exit(1);
    }

    fprintf(fp, "ID = %s, name = %s", num, name);
    fclose(fp);
    return 0;
}