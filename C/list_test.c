#include <stdio.h>

void update(int *a, int b)
{
    if(*a < b){
        *a = b;
    }
    return;
}

int main()
{
    int a[3] = {1, 2, 3};
    int b = 2;
    int i;

    printf("%d %d %d\n", a[0], a[1], a[2]);
    for(i = 0; i < 3; i++){
        update(&(a[i]), b);
    }
    printf("%d %d %d\n", a[0], a[1], a[2]);

    return 0;
}