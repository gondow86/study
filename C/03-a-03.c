#include <stdio.h>

int main()
{
    int x;
    int i;
    int ans;
    ans = 1;
    printf("input an integer:");
    scanf("%d", &x);
    for(i = x; i > 0; i--){
        ans = ans * i;
    }
    printf("%d! == %d\n", x, ans);
    return 0;
}
