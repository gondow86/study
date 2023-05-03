#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double i, j;
    // printf("%d\n", argc);
    if(argc != 3){
        printf("Error\n");
        exit(1);
    }

    i = atof(argv[1]);
    j = atof(argv[2]);

    printf("%lf + %lf = %lf\n", i, j, i+j);
    printf("%lf - %lf = %lf\n", i, j, i-j);
    printf("%lf * %lf = %lf\n", i, j, i*j);
    printf("%lf / %lf = %lf\n", i, j, i/j);
    
    return 0;   
}