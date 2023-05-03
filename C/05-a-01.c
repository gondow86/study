#include <stdio.h>

int main()
{
    struct point{
        float x;
        float y;
    };
    
    struct point p1, p2;
    float a, b;
    
    printf("input first point (x1 y1):");
    scanf("%f %f", &(p1.x), &(p1.y));
    printf("input first point (x2 y2):");
    scanf("%f %f", &(p2.x), &(p2.y));
    a = (p2.y - p1.y) / (p2.x - p1.x);
    b = p1.y - a * p1.x;
    if(b < 0){
        printf("linear function:y = %fx %f\n", a, b);
    } else if(b == 0){
        printf("linear function:y = %fx\n", a);
    } else{
        printf("linear function:y = %fx + %f\n", a, b);
    }
    

    return 0;
}