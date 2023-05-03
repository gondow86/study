#include <stdio.h>
#include <stdlib.h>

struct data_t{
    struct data_t *next, *prev;
    int i;
    int counter;
};

struct data_t head;

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

struct data_t *insert_pos(struct data_t *p, struct data_t *w)
{
    struct data_t *insert_pos;

    if(p->next == p){
        insert_pos = p->next;
    }
    for(p = p->next; p != &head; p = p->next){
        if((w->i >= p->i) && (p == head.prev)){
            insert_pos = p->next;
            return insert_pos;
        } else if(w->i < p->i){
            insert_pos = p;
            return insert_pos;
        }
    }

    return insert_pos;
}

void remove_(struct data_t *p){
    struct data_t *p_prev, *p_next;
    p_prev = p->prev;
    p_next = p->next;
    p_prev->next = p_next;
    p_next->prev = p_prev;
    free(p);

    return;
}



int main()
{
    head.next = &head;
    head.prev = &head;
    struct data_t *p;
    struct data_t *pos;
    struct data_t *p_prev;
    int d;

    for(;scanf("%d", &d) != EOF;){
        p = (struct data_t*)malloc(sizeof(struct data_t));
        if(p == NULL){
            printf("out of memory\n");
            exit(1);
        }
        p->counter = 1; 
        p->i = d;
        pos = insert_pos(&head, p);
        insert(pos, p);
    }

    for(p = head.next; p != &head; p = p->next){
        p_prev = p->prev;
        if(p->i == p_prev->i){
            p->counter += p_prev->counter;
            remove_(p_prev);
        }
    }

    for(p = head.next; p != &head; p = p->next){
        printf("[%d]:%d\n", p->i, p->counter);
    }

    return 0;
}