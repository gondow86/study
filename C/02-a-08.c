#include <stdio.h>

int main()
{
    float salt;
    float water;
    printf("Input weight of salt(g):");
    scanf("%f", &salt);
    printf("Input weight of water(g):");
    scanf("%f", &water);
    if((salt / (salt + water)) <= 0.2628){
        printf("%f(g) of salt dissolves in %f(g) of water.\n", salt, water);
    } else{
        printf("%f(g) of salt does not dissolove in %f(g) of water.\n", salt, water);
    }
    return 0;
}