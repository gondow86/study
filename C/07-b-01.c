#include <stdio.h>

float my_pow(int a, int b)
{
    if(b > 0){
        if(b == 1){
            return (float) a;
        } else {
            return (float) a * my_pow(a, b - 1);
        }
    } else {
        if(b == -1){
            return (float) 1 / a;
        } else {
            return my_pow(a, b + 1) / (float) a;
        }
    }
}

int main()
{
    int a, b;
    float ans;

    printf("Input two integers:");
    scanf("%d %d", &a, &b);
    ans = my_pow(a, b);
    printf("a^b = %f\n", ans);

    return 0;
}