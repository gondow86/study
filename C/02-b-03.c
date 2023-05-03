#include <stdio.h>
/*
* 先に入力する時刻を, 2つ目の時刻よりも後とする.
*/
int main()
{
    int h1;
    int h2;
    int m1;
    int m2;
    printf("after time h1:m1\n");
    printf("input h1 m1:");
    scanf("%d %d", &h1, &m1);
    printf("before time h2:m2\n");
    printf("input h2 m2:");
    scanf("%d %d", &h2, &m2);
    printf("time subtraction(min) is %d\n", (60 * h1 + m1) - (60 * h2 + m2));
    if(m1 >= m2){
        printf("time subtraction is %d:%d\n", h1 - h2, m1 - m2);
    } else if(m2 > m1){
        printf("time subtraction is %d:%d\n", h1 - h2 - 1, m2 - m1);
    }
    return 0;
}