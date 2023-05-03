#include <stdio.h>

int main()
{
    int a;
    int b;
    int c;
    int first;
    int second;
    int third;
    printf("Input 1:");
    scanf("%d", &a);
    printf("Input 2:");
    scanf("%d", &b);
    printf("Input 3:");
    scanf("%d", &c);

    if(a >= b && a >= c){
        third = a;
        if(b >= c){
            second = b;
            first = c;
        } else{
            second = c;
            first = b;
        }
    } else if(b >= a && b >= c){
        third = b;
        if(a >= c){
            second = a;
            first = c;
        } else{
            second = c;
            first = a;
        }    
    } else{
        third = c;
        if(a >= b){
            second = a;
            first = b;
        } else{
            second = b;
            first = a;
        }    
    }
    printf("Sorted: %d, %d, %d\n", first, second, third);
}