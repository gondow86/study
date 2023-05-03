#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sencount = 0;
    int wordcount = 0;
    FILE *fp;
    int i = 0;
    int c;

    if((fp = fopen("11-a-04.txt", "r")) == NULL){
        perror("11-a-04.txt");
        exit(1);
    }
    while((c = fgetc(fp)) != EOF){
        if(c == '.'){
            sencount++;
        }
    }
    printf("sentence:%d\n", sencount);

    fseek(fp, 0, SEEK_SET);

    while((c = fgetc(fp)) != EOF){
        if(c == ' '){
            wordcount++;
        }
    }
    // ファイル最後の単語もカウント
    wordcount++;
    printf("word:%d\n", wordcount);

    fclose(fp);

    return 0;
}