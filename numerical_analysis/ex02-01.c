#include <stdio.h>
int main(void) {
    int a1, a2;
    long b1, b2;
    float c1, c2, c3;
    double d1, d2, d3;
    a1 = 5/2;
    a2 = 5.0/2.0;
    b1 = 5/2;
    b2 = 5.0/2.0;
    c1 = 5/2;
    c2 = 5.0/2.0;
    c3 = 5/2.0;
    d1 = 5/2;
    d2 = 5.0/2.0;
    d3 = 5/2.0;
    printf("a1 = %d, a2 = %d\n",a1, a2);
    printf("b1 = %ld, b2 = %ld\n",b1,b2);
    printf("c1 = %f, c2 = %f, c3 = %f\n",c1,c2,c3);
    printf("d1 = %f, c2 = %f, d3 = %f\n",d1,d2,d3);
}