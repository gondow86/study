#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[100];
    FILE *fp_in;
    char in[100];
    FILE *fp_out;
    char out[100];
    int i, n;
    char *p;

    printf("input filename:");
    if(fgets(in, 100, stdin) != NULL){
        p = strrchr(in, '\n');
        if(p != NULL){
            *p = '\0';
        }
    }
    printf("loop num:");
    scanf("%d%*c", &n);
    printf("output filename:");
    if(fgets(out, 100, stdin) != NULL){
        p = strrchr(out, '\n');
        if(p != NULL){
            *p = '\0';
        }
    }

    if((fp_in = fopen(in, "r")) == NULL){
        perror(in);
        exit(1);
    }
    if((fp_out = fopen(out, "w")) == NULL){
        perror(out);
        exit(1);
    }
    
    for(i = 0; i < n; i++){
        while(fgets(buffer, 100, fp_in) != NULL){
            fputs(buffer, fp_out);
        }
        fseek(fp_in, 0, SEEK_SET);
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}