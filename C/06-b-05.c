#include <stdio.h>
#include <stdlib.h>

struct data {
    struct data *id_fp, *id_bp;
    struct data *ave_fp, *ave_bp; 
    int id;
    int math;
    int sci;
    int eng;
    float ave;
};

struct data head;

void ave_insert(struct data *p, struct data *w)
{
    struct data *p_prev;
    p_prev = p->ave_bp;
    w->ave_fp = p;
    w->ave_bp = p_prev;
    p_prev->ave_fp = w;
    p->ave_bp = w;

    return;
}

void id_insert(struct data *p, struct data *w)
{
    struct data *p_prev;
    p_prev = p->id_bp;
    w->id_fp = p;
    w->id_bp = p_prev;
    p_prev->id_fp = w;
    p->id_bp = w;

    return;
}

struct data *ave_pos(struct data *p, struct data *w)
{
    struct data *ave_pos;

    if(p->ave_fp == p){
        ave_pos = p->ave_fp;
    }
    for(p = p->ave_fp; p != &head; p = p->ave_fp){
        if((w->ave >= p->ave) && (p == head.ave_bp)){
            ave_pos = p->ave_fp;
            return ave_pos;
        } else if(w->ave < p->ave){
            ave_pos = p;
            return ave_pos;
        }
    }

    return ave_pos;
}

struct data *id_pos(struct data *p, struct data *w)
{
    struct data *id_pos;

    if(p->id_fp == p){
        id_pos = p->id_fp;
    }
    for(p = p->id_fp; p != &head; p = p->id_fp){
        if((w->id >= p->id) && (p == head.id_bp)){
            id_pos = p->id_fp;
            return id_pos;
        } else if(w->id < p->id){
            id_pos = p;
            return id_pos;
        }
    }
    
    return id_pos;
}

int main()
{
    head.ave_fp = &head;
    head.ave_bp = &head;
    head.id_fp = &head;
    head.id_bp = &head;
    struct data *p;
    struct data *pos;
    int d;
    int i;

    for(;;){
        printf("Input ID, Math, Science, English:");
        p = (struct data*)malloc(sizeof(struct data));
        if(p == NULL){
            printf("out of memory\n");
            exit(1);
        }
        scanf("%d %d %d %d", &(p->id), &(p->math), &(p->sci), &(p->eng));
        if(p->id < 0){
            break;
        } else {
            pos = id_pos(&head, p);
            id_insert(pos, p);
            p->ave = (float) (p->math + p->sci + p->eng) / 3;
            pos = ave_pos(&head, p);
            ave_insert(pos, p);
        }
    }

    printf("[ID]\n");
    for(p = head.id_fp; p != &head; p = p->id_fp){
        printf("ID:%d, Math:%d, Science:%d, English:%d\n", p->id, p->math, p->sci, p->eng);
    }

    printf("[Average]\n");
    for(p = head.ave_fp; p != &head; p = p->ave_fp){
        printf("Average: %f, ID:%d\n", p->ave, p->id);
    }

    return 0;
}