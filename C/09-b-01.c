#include <stdio.h>

void get_arr3x3(int a[][3])
{
    int m, n;
    for(m = 0; m < 3; m++){
        for(n = 0; n < 3; n++){
            scanf("%d", &a[m][n]);
        }
    }

    return;
}

void sum_arr3x3(int a[][3], int b[][3], int c[][3])
{
    int m, n;
    for(m = 0; m < 3; m++){
        for(n = 0; n < 3; n++){
            c[m][n] = a[m][n] + b[m][n];
        }
    }
}

void print_arr3x3(int a[][3])
{
    int m, n;
    for(m = 0; m < 3; m++){
        for(n = 0; n < 3; n++){
            printf("%d ", a[m][n]);
        }
        printf("\n");
    }

    return;
}

int main()
{
    int a[3][3];
    int b[3][3];
    int c[3][3];
    int m, n;

    get_arr3x3(a);
    printf("a\n");
    print_arr3x3(a);

    get_arr3x3(b);
    printf("b\n");
    print_arr3x3(b);

    for(m = 0; m < 3; m++){
        for(n = 0; n < 3; n++){
            c[m][n] = 0;
        }
    }

    sum_arr3x3(a, b, c);
    printf("a + b\n");
    print_arr3x3(c);

    return 0;
}