#include <stdio.h>
#include <stdlib.h>

struct number {
    int i;
    struct number *next;
};

struct number head;

int main()
{
    struct number *p;
    p = (struct number *)malloc(sizeof(struct number));
    if (p == NULL) {
        printf("out of memory");
        exit(1);
    }
    int j;
    head.next = p;

    printf("input 5 numbers:\n");
    for (j = 1; j <= 5; j++){
        scanf("%d", &(p->i));
        if (j == 5){
            p->next = NULL;
        } else {
            p->next = (struct number *)malloc(sizeof(struct number));
            if (p->next == NULL) {
                printf("out of memory");
                exit(1);
            }
            p = p->next;
        }
    }

    printf("number list:");
    for (p = head.next; p != NULL; p = p->next){
        if (p->next == NULL){
            printf("%d\n", p->i);
        } else{
            printf("%d,", p->i);
        }
    }

    return 0;

}