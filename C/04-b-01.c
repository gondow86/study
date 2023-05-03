#include <stdio.h>

int main()
{
    char a[100];
    int i;
    int sum = 0;
    int counter = 0;
    for(i = 0; i < 100; i++){
        scanf("%c", &a[i]);
        if(a[i] == 'E'){
            printf("Sum is: %d\n", sum);
            printf("Average is: %f\n", (float) sum / counter);
            
            return 0;
        } else if(a[i] >= '0' && a[i] <= '9'){ //char型なので数字は0~9, 入力は正の整数だが, '数字以外が入力されたら'という指示と, 0を含めても結果は変わらないのでこのようにした.
            sum += a[i] - '0';
            counter += 1;
        } else if(a[i] == '\n'){
            //　何もしない
        } else{
            printf("Illegal input: %c\n", a[i]);
        }
    }
}