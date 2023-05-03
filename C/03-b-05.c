#include <stdio.h>

int main()
{
    int a[100];
    int i;
    int j;
    int fin_num;
    int counter;
    for (i = 0; i < 100; i++){
        scanf("%d", &a[i]);
        if(a[i] < 0 || a[i] > 10){
            printf("Illegal input:%d\n", a[i]);
        }
        if(a[i] == 0){
            fin_num = i;
            break; 
        }
    }

    for (i = 1; i < 10; i++){
        counter = 0;
        for (j = 0; j < fin_num; j++){
            if(a[j] == i){
                counter += 1;
            }
        }
        printf("[%d]: %d\n", i, counter);
    }
    
    return 0;
}