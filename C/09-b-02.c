#include <stdio.h>

void find_zero(char *a, int n)
{
    int i;

    //nが引数にあるのでwhile文でなくfor文で
    for(i = 0; i < n && (*a = getchar()) != '\n'; i++){
        if(i == 0){
            printf("Zero in ");
        }
        if(*a == '0'){
            printf("%d ", i);
        }
        a++;
    }
    printf("\n");

    return;
}

int main()
{
    char c[100];
    char *p;
    p = c;

    find_zero(p, 100);

    return 0;
}