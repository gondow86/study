#include <stdio.h>
#include <stdlib.h>
struct number{
    int i;
    struct number *next, *prev;
};

struct number head;

void insert(struct number *p_prev, struct number *p)
{
    struct number *p_next;
    p_next = p_prev->next;
    p->next = p_next;
    p->prev = p_prev;
    p_prev->next = p;
    p_next->prev = p;
    
    return;
}

int main()
{
    int j;
    struct number *p;
    head.next = &head;
    head.prev = &head;
    
    printf("input 5 numbers:\n");
    /*insert*/
    for(j = 0; j < 5; j++){ 
        p = (struct number*)malloc(sizeof(struct number));
        if (p == NULL) {
            printf("out of memory\n");
            exit(1);
        }
        scanf("%d", &(p->i));
        insert(&head, p);
    }

    /*print from tail*/
    for(p = head.prev; p != &head; p = p->prev){
        if(p == head.prev){
            printf("number list:");
        }
        
        if(p == head.next){
            printf("%d\n", p->i);
        } else {
            printf("%d ", p->i);
        }
    }

    /*print from head*/
    for(p = head.next; p != &head; p = p->next){
        if(p == head.next){
            printf("number list:");
        }
        
        if(p == head.prev){
            printf("%d\n", p->i);
        } else {
            printf("%d ", p->i);
        }
    }

    return 0;
}