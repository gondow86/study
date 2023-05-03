#include <stdio.h>
#include <stdlib.h>

struct calc_result {
    float sum;
    float diff;
    float pro;
    float quo;
};

struct calc_result* get_calc_result(float a, float b)
{
    struct calc_result *address;
    
    address = (struct calc_result *)malloc(sizeof(struct calc_result));
    address->sum = a + b;
    address->diff = a - b;
    address->pro = a * b;
    if(b == 0){
        address->quo = (float) 0;
    } else
    {
        address->quo = a / b;
    }

    return address;
}

int main()
{
    float a,b;
    struct calc_result* address;

    printf("input two integers:");
    scanf("%f %f", &a, &b);
    address = get_calc_result(a, b);
    if(b >= 0){
        printf("%f + %f = %f\n", a, b, address->sum);
        printf("%f - %f = %f\n", a, b, address->diff);
        printf("%f × %f = %f\n", a, b, address->pro);
        printf("%f ÷ %f = %f\n", a, b, address->quo);
    } else{
        printf("%f + (%f) = %f\n", a, b, address->sum);
        printf("%f - (%f) = %f\n", a, b, address->diff);
        printf("%f × (%f) = %f\n", a, b, address->pro);
        printf("%f ÷ (%f) = %f\n", a, b, address->quo);
    }

    free(address);
    return 0;
}