#include <stdlib.h>
#include <stdio.h>

struct data{
    struct data *fp, *bp;
    int num;
};

void push(struct data *p, int n)//pはhead, nは入れたい値
{
    struct data *w;
    w =  (struct data*)malloc(sizeof(struct data));
    if(w == NULL){
        printf("out of memory\n");
        exit(1);
    }
    w->num = n;

    struct data *w_fp;
    w_fp = p->fp;
    w->fp = w_fp;
    w->bp = p;
    p->fp = w;
    w_fp->bp = w;
    printf("push %d\n", w->num);
    
    return;
}

int pop_queue(struct data *p)//pはhead
{
    int pop_num;
    struct data *w;
    struct data *w_bp;

    w = p->bp; //wは消したい構造体
    p->bp = w->bp;
    w_bp = w->bp;
    w_bp->fp = p;
    pop_num = w->num;
    free(w);
    printf("pop %d(queue)\n", pop_num);
    
    return pop_num;
}

int pop_stack(struct data *p)
{
    int pop_num;
    struct data *w;
    struct data *w_fp;

    w = p->fp; //wは消したい構造体
    w_fp = w->fp;
    w_fp->bp = p;
    p->fp = w_fp;
    pop_num = w->num;
    free(w);
    printf("pop %d(stack)\n", pop_num);

    return pop_num;
}

void print_data(struct data *p)
{
    struct data *sentinel;
    printf("stored nums:");
    sentinel = p;
    for(p = p->bp; p != sentinel; p = p->bp){
        if(p == sentinel->fp){
            printf("%d\n", p->num);
        } else {
            printf("%d ", p->num);
        }
    }

    return;
}

int main()
{
    int i;
    struct data sentinel;
    sentinel.fp = sentinel.bp = &sentinel; //headの初期化
    push(&sentinel, 1);
    print_data(&sentinel);
    push(&sentinel, 2);
    print_data(&sentinel);
    push(&sentinel, 3);
    print_data(&sentinel);
    pop_queue(&sentinel);
    print_data(&sentinel);
    pop_stack(&sentinel);
    print_data(&sentinel);
    return 0;
}