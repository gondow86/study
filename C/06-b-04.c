#include <stdio.h>
#include <stdlib.h>

struct data_t{
    struct data_t *next, *prev;
    int i;
};

struct data_t head;

void remov(struct data_t *p, int index)
{
    int j = 0;
    struct data_t *p_next;
    struct data_t *p_prev;
    
    for(p = p->next; p != &head; p = p->next){
        if(j == index){
            p_next = p->next;
            p_prev = p->prev;
            p_prev->next = p_next;
            p_next->prev = p_prev; 
            free(p);
            break;
        }
        j++;
    }

    return;
}
void insert(struct data_t *p, struct data_t *w)
{
    struct data_t *p_prev;
    p_prev = p->prev;
    w->next = p;
    w->prev = p_prev;
    p_prev->next = w;
    p->prev = w;

    return;
}


void printall(struct data_t *p)
{
    for(p = p->next; p != &head; p = p->next){
        printf("[p:%p, bp:%p, fp:%p, data:%d]\n", p, p->prev, p->next, p->i);
    }
    return;
}

int main()
{
    head.next = &head;
    head.prev = &head;
    struct data_t *p;
    int d;
    int counter = -1;

    printf("State Input\n");
    for(;scanf("%d", &d) != EOF;){
        p = (struct data_t*)malloc(sizeof(struct data_t));
        if(p == NULL){
            printf("out of memory\n");
            exit(1);
        }
        p->i = d;
        insert(&head, p);
        counter++;
    }
    
    printf("State Remove\n");
    for(;scanf("%d", &d) != EOF;){
        if(d < 0 || d > counter){
            printf("List doesn't have the index number:%d\n", d);
        } else{
            remov(&head, d);
            counter--;
        }
    }
    printall(&head);
    
    return 0;
}