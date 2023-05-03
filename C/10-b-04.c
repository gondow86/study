#include <stdio.h>
#include <string.h>

/*s2の中にs1が含まれているか判断する*/
int mystrstr(char *s1, char *s2)
{
    int i, j, k;
    int n1, n2;
    
    /*改行コードを除いた文字数*/
    n1 = strlen(s1) - 1;
    n2 = strlen(s2) - 1;

    for(i = 0; i <= n2 - n1; i++){
        /*もし単語の先頭と文字が一致したら*/
        if(s2[i] == s1[0]){
            for(j = 0; j < n1; j++){
                if(s1[j] == s2[i + j]){
                    if(j == n1 -1){
                        return 0;
                    }
                } else {
                    break;
                }
            }
        }
    }

    return 1;
}

int main()
{
    char sentence[50];
    char word[50];
    int res;
    char *p;

    printf("Input a sentence:");
    fgets(sentence, 30, stdin);
    printf("Input a word:");
    fgets(word, 30, stdin);
    res = mystrstr(word, sentence);
    p = strchr(word, '\n');
    if(p != NULL){
        *p = '\0';
    }
    if(res == 0){
        printf("The word (%s) exists\n", word);
    } else {
        printf("The word (%s) doesn't exist\n", word);
    }
    
    return 0;
}