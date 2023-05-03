#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a_buffer[128];
    char b_buffer[128];
    FILE *fp_a;
    char a[128];
    FILE *fp_b;
    char b[128];
    int c;
    char *p;

    printf("File1:");
    if(fgets(a, 128, stdin) != NULL){
        p = strrchr(a, '\n');
        if(p != NULL){
            *p = '\0';
        }
    }
    printf("File2:");
    if(fgets(b, 128, stdin) != NULL){
        p = strrchr(b, '\n');
        if(p != NULL){
            *p = '\0';
        }
    }

    if((fp_a = fopen(a, "r")) == NULL){
        perror(a);
        exit(1);
    }
    if((fp_b = fopen(b, "r")) == NULL){
        perror(b);
        exit(1);
    }

    while(fscanf(fp_a, "%s", a_buffer) != EOF){
        fscanf(fp_b, "%s", b_buffer);
        if((c = strcmp(a_buffer, b_buffer)) != 0){
            printf("Not Equal\n");

            return 0;
        }
    }

    printf("Equal\n");
    fclose(fp_a);
    fclose(fp_b);

    return 0;
}