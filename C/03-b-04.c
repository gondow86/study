#include <stdio.h>

int main()
{
    int size;
    int a[100];
    int i;
    int max;
    int min;
    int sum;
    sum = 0;
    printf("input array size:");
    scanf("%d", &size);
    printf("input array elements:");
    for (i = 0; i < size; i++){
        scanf("%d", &a[i]);
        if(i == 0){
            max = a[i];
            min = a[i];
        } else if(i > 0 && max < a[i]){
            max = a[i];
        } else if(i > 0 && min > a[i]){
            min = a[i];
        }
        sum += a[i];
    }

    printf("max: %d, min: %d, average:%f\n", max, min, sum / (float) size);

    return 0;    
}