#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point{
    float x;
    float y;
};
    
struct circle{
    struct point p;
    float r;
};

int circle_intersect(struct circle c1, struct circle c2)
{   
    int point_num;
    float distance;

    distance = sqrt((c1.p.x - c2.p.x)*(c1.p.x - c2.p.x) + (c1.p.y - c2.p.y)*(c1.p.y - c2.p.y));
    if ((distance * distance) < ((c1.r - c2.r) * (c1.r - c2.r)) || (distance * distance) > ((c1.r + c2.r) * (c1.r + c2.r))) {
        point_num = 0;
    } else if ((distance * distance) == (c1.r + c2.r) * (c1.r + c2.r) || (distance * distance) == (c1.r - c2.r) * (c1.r - c2.r)) {
        point_num = 1;
    } else {
        point_num = 2;
    }
    printf("Circles have %d intersect point\n", point_num);
    // printf("%f %f", distance, (c1.r + c2.r) * (c1.r + c2.r));

    return point_num;
}

int main() 
{
    int ans;
    struct circle c1;
    struct circle c2;

    printf("Input 1st Circle(x, y, r):");
    scanf("%f %f %f", &(c1.p.x), &(c1.p.y), &(c1.r));
    printf("Input 2nd Circle(x, y, r):");
    scanf("%f %f %f", &(c2.p.x), &(c2.p.y), &(c2.r));
    ans = circle_intersect(c1, c2);

    return 0;
}