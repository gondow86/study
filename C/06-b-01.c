#include <stdio.h>
#include <stdlib.h>

struct data_t{
    struct data_t *next, *prev;
    int i;
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

void printasc(struct data_t *p)
{
    for(p = p->next; p != &head; p = p->next){
        if(p == head.prev){
            printf("%d\n", p->i);
        } else{
            printf("%d", p->i);
        }
    }

    for(p = p->prev; p != &head; p = p->prev){
        if(p == head.next){
            printf("%d\n", p->i);
        } else {
            printf("%d", p->i);
        }
    }

    return;
}

int main()
{
    head.next = &head;
    head.prev = &head;
    struct data_t *p;
    struct data_t *pos;
    int d;

    for(;scanf("%d", &d) != EOF;){
        p = (struct data_t*)malloc(sizeof(struct data_t));
        if(p == NULL){
            printf("out of memory\n");
            exit(1);
        }
        p->i = d;
        pos = insert_pos(&head, p);
        insert(pos, p);
    }

    printasc(&head);

    return 0;
}