#include <stdio.h>

int main()
{
    int p;
    int q = 1;
    int r = 0;

    printf("Input number:");
    scanf("%d", &p);
    if(p <= 0){
        printf("Incorrect Input\n");
    } else {
        printf("%d is divisible by ", p);
        do {
            r = p % q;
            if((r == 0) && (p != q)){
                printf("%d ", q);
            } else if((r == 0) && (p == q)){
                printf("%d\n", q);
            }
            q++;
        } while (p >= q);
    }

    return 0;
}