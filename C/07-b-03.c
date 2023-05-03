#include <stdio.h>
#include <stdlib.h>

void min_update(int *a, int b)
{
    if(*a > b){
        *a = b;
    }

    return;
}

int main()
{
    int h[10];
    int cost_min[10];
    int i;    
    for(i = 0; i < 10; i++){
        if(i == 0){
            cost_min[0] = 0;
        } else {
            cost_min[i] = 101;
        }
        
    }
    int n;

    printf("Input N:");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &(h[i]));
    }
    for(i = 1; i < n; i++){
        if(i == 1){
            min_update(&(cost_min[i]), cost_min[i - 1] + abs(h[i] - h[i - 1]));
        } else {
            min_update(&(cost_min[i]), cost_min[i - 1] + abs(h[i] - h[i - 1]));
            min_update(&(cost_min[i]), cost_min[i - 2] + abs(h[i] - h[i - 2]));
        }
    }
    printf("Minimum cost is %d\n", cost_min[n - 1]);

    return 0;
}