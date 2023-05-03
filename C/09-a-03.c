#include <stdio.h>

void init_array(float f[], int n)
{
    int i;

    for(i = 0; i < n; i++){
        f[i] = 0.0;
        printf("f[%d]:%f\n", i, f[i]);
    }
}

int main()
{
    float f[10];
    int n = 10;

    init_array(f, n);

    return 0;

}