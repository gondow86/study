#include <stdio.h>

int main()
{
    int score;
    printf("input your score:");
    scanf("%d", &score);
    if(score >= 50 && score <= 100){
        printf("you passed the examination.\n");
    } else if(score < 50 && score >= 0){
        printf("you failed the examination.\n");
    } else{
        printf("error:input from 0 to 100.\n");
    }
    return 0;
}