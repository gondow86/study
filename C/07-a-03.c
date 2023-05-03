#include <stdio.h>

int tousa(int a, int d, int n)
{
    int an;

    if (n == 1){
        printf("[%d]:%d\n", n, a);
        return a + d;
    } else {
        an = tousa(a, d, n - 1);
        printf("[%d]:%d\n", n, an);
        return a + n * d;
    }
}

int main()
{
    int a, d, n;

    printf("Input a d n:");
    scanf("%d %d %d", &a, &d, &n);
    tousa(a, d, n);

    return 0;
}