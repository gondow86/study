#include <stdio.h>

int main()
{
    struct point{
        float x;
        float y;
    };
    
    printf("char          %lu(byte)\n", sizeof(char));
    printf("short int     %lu(byte)\n", sizeof(short int));
    printf("int           %lu(byte)\n", sizeof(int));
    printf("long int      %lu(byte)\n", sizeof(long int));
    printf("float         %lu(byte)\n", sizeof(float));
    printf("double        %lu(byte)\n", sizeof(double));
    printf("struct point  %lu(byte)\n", sizeof(struct point));

    return 0;
}