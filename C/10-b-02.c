#include <stdio.h>
#include <string.h>
#define MAX_LEN 256

/*s2を逆にしたs1を作成, 改行コードは含まれる前提で良いとのこと*/
void mystrrev(char *s1, char *s2)
{
    int i;
    int n;
    
    n = strlen(s2);
    for(i = 0; i <= n - 2; i++){
        s1[i] = s2[n - 2 - i];
    }
    s1[n - 1] = '\0';
    return;
}

int main()
{
    char str2[MAX_LEN];
    char str1[MAX_LEN];

    fgets(str2, MAX_LEN, stdin);
    printf("[IN]%s", str2);
    mystrrev(str1, str2);
    printf("[REV]%s\n", str1);

    return 0;
}