#include <stdio.h>
#include <stdlib.h>

struct point{
    int a;
    int b;
    int c;
};

int main()
{
    struct point* p;
    //pの領域を動的に確保する
    p = (struct point *)malloc(sizeof(struct point));
    //数字３つを入力にとる
    printf("Input three nums:");
    scanf("%d %d %d", &(p->a), &(p->b), &(p->c));
    printf("%d + %d + %d = %d\n", p->a, p->b, p->c, p->a + p->b + p->c);

    //確保した領域を解放
    free(p);
    return 0;
}