#include <stdio.h>
#include <stdlib.h>

struct data_t{
    struct data_t *next, *prev;
    int i;
};

struct data_t head;

void insert(struct data_t *p, struct data_t *w)//pの前にwを入れる
{
    struct data_t *p_prev;
    p_prev = p->prev;
    w->next = p;
    w->prev = p_prev;
    p_prev->next = w;
    p->prev = w;

    return;
}


void printall()//先頭要素(head?)を受けとり連結されている要素のアドレス, fp, bpのアドレス, データの中身を全て表示
{
    struct data_t *p;
    for(p = head.next; p != &head; p = p->next){
        printf("[p:%p, bp:%p, fp:%p, data:%d]\n", p, p->prev, p->next, p->i);
    }
    return;
}

void remove_(struct data_t *p){ //stdio.hのremoveと競合しないように
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
    int d;

    for(;scanf("%d", &d) != EOF;){//EOFを受け取るまでに...
        p = (struct data_t*)malloc(sizeof(struct data_t));
        if(p == NULL){
            printf("out of memory\n");
            exit(1);
        }
        p->i = d;
        insert(&head, p);
    }

    printall();

    for(p = head.next; p != &head; p = head.next){
        remove_(p);
    }
    
    return 0;
}