#include <stdio.h>
#include <stdlib.h>

int greatest_common_divisor(int a, int b)
{
    int gcd;

    if(b == 0){
        gcd = a;
        printf("%d\n", a);
        return gcd;
    } else {
        greatest_common_divisor(b, a % b);
    }
}

int main()
{
    int res;
    int a;
    int b;

    printf("Input two integers:");
    scanf("%d %d", &a, &b);
    res = greatest_common_divisor(a, b);
    printf("%d", res);
    printf("greatest common divisor is %d\n", res);

    return 0;
}