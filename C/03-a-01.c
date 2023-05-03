#include <stdio.h>

int main()
{
    int x;
    int y;

    printf("input two integer:");
    scanf("%d %d", &x, &y);
    printf("%10.4f\n", (float) x + (float) y);
    printf("%10.4f\n", (float) x - (float) y);
    printf("%10.4f\n", (float) x * (float) y);
    printf("%10.4f\n", (float) x / (float) y);
    return 0;
}