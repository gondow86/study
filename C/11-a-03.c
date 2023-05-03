#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[32];
    FILE *fp;
    int hei;
    int wei;

    if((fp = fopen("11-a-03.txt", "r")) == NULL){
        perror("11-a-03.txt");
        exit(1);
    }
    while(fscanf(fp, "%s %d %d", name, &hei, &wei) != EOF){
        printf("name = %s, height = %d, weight = %d\n", name, hei, wei);
    }
    fclose(fp);

    return 0;
}