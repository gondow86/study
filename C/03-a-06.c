#include <stdio.h>

int main()
{
    int a[20] = {1, 1};
    int i;
    for(i = 2; i < 20; i++){
        a[i] = a[i - 1] + a[i - 2];
    }
    for(i = 0; i < 20; i++){
        printf("fib[%d]: %d\n", i + 1, a[i]);
    }

    return 0;
}