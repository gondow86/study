#include <stdio.h>
#include <string.h>
#define MAX_LEN 256

/*s2をn回繰り返したs1を作成 改行が含まれる前提*/
void strrpt(char *s1, char *s2, int n)
{
    int i;
    int j = 0;
    int k = 0;

    for(i = 0; i < n; i++){
        while(j <= (strlen(s2) - 2)){
            s1[k] = s2[j];
            j++;
            k++;
        }
        j = 0;
    }
    s1[k] = '\0';

    return;
}

int main()
{
    char str1[MAX_LEN];
    char str2[MAX_LEN];
    int n;

    printf("Input string:");
    fgets(str2, MAX_LEN, stdin);
    printf("Input repeat time:");
    scanf("%d", &n);
    printf("[ORG]:%s", str2);
    strrpt(str1, str2, n);
    printf("[RPT]:%s\n", str1);

    return 0;
}