#include <stdio.h>

int main()
{
    int p, q;

    printf("Input a:");
    scanf("%d", &p);
    printf("Input b:");
    scanf("%d", &q);
    printf("%d + %d = %d\n", p, q, p + q);
    printf("%d - %d = %d\n", p, q, p - q);
    printf("%d * %d = %d\n", p, q, p * q);
    printf("%d / %d = %d\n", p, q, p / q);
    printf("%#x & %#x = %#x\n", p, q, p & q);
    printf("%#x | %#x = %#x\n", p, q, p | q);
    printf("%#x ^ %#x = %#x\n", p, q, p ^ q);
    printf("%#x << %#x = %#x\n", p, q, p << q);
    printf("%#x >> %#x = %#x\n", p, q, p >> q);

    return 0;
}