#include <stdio.h>
#include <stdlib.h>

void quicksort(int a[], int left, int right)
{
    int i, j, somewhere;
    int pivot;
    int tmp;
    if(left < right){
        somewhere = (left + right) / 2;
        pivot = a[somewhere];
        i = left;
        j = right;
        printf("%d %d %d %d\n", left, right, somewhere, pivot);
        do{
            while(a[i] < pivot){
                i = i + 1;
            }
            while(a[j] > pivot){
                j = j - 1;
            }
            if(i <= j){
                // swap
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                i = i + 1;
                j = j - 1;
            }
        } while(i <= j);
        quicksort(a, left, j);
        quicksort(a, i, right);
    }

    return;
}

int main()
{
    FILE *fp;
    FILE *out;
    int array[1000000];
    int n = 1000000;
    int i = 0;
    int c;

    if((fp = fopen("11-b-02.txt", "r")) == NULL){
        perror("11-b-02.txt");
        exit(1);
    }
    while(fscanf(fp, "%d", &c) != EOF){
        array[i] = c;
        i++;
    }
    printf("ok\n");
    quicksort(array, 0, n - 1);

    if((out = fopen("sorted.txt", "w")) == NULL){
        perror("sorted.txt");
        exit(1);
    }

    for(i = 0; i < n; i++){
        if(i != n - 1){
            fprintf(out, "%d\n", array[i]);
        } else{
            fprintf(out, "%d", array[i]);
        }
    }

    fclose(fp);
    fclose(out);

    return 0;
}