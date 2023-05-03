#include <stdio.h>
#include <stdlib.h>

struct result{
    struct result *next, *prev;
    int c;
};

struct result head;

void insert(struct result *p, struct result *w)
{
    struct result *p_prev;
    p_prev = p->prev;
    w->next = p;
    w->prev = p_prev;
    p_prev->next = w;
    p->prev = w;

    return;
}

//p(head)を受け取り, 昇順に挿入したいwの挿入位置を返す
struct result *insert_pos(struct result *p, struct result *w)
{
    struct result *pos;

    if(p->next == p){
        pos = p->next;
        return pos;
    }
    for(p = p->next; p != &head; p = p->next){
        if((w->c >= p->c) && (p == head.prev)){
            pos = p->next;
            return pos;
        } else if(w->c < p->c){
            pos = p;
            return pos;
        }
    }
    
    return pos;
}

int main()
{
    head.next = &head;
    head.prev = &head;
    struct result *p;
    struct result *pos;
    int askii;

    while((askii = getchar()) > '9' || askii < '0'){
        p = (struct result*)malloc(sizeof(struct result));
        if(p == NULL){
            printf("out of memory\n");
            exit(1);
        }
        if(askii == '\n'){
            continue;
        }
        p->c = askii;
        pos = insert_pos(&head, p);
        insert(pos, p);
    }

    for(p = head.next; p != &head; p = p->next){
        printf("%c", p->c);
    }
    printf("\n");

    return 0;
}