#include <stdio.h>
int main(){
    int a[5][5];
    int i;
    int j;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(i == j){
                a[i][j] = 1;
            } else{
                a[i][j] = 0;
            }
            
            if(j == 4){
                printf("%d\n", a[i][j]);
            } else{
                printf("%d ", a[i][j]);
            }
        }
    }
    return 0;
}