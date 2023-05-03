#include <stdio.h>

void disp_array(int array[][4])
{
    int m, n;
    for(m = 0; m < 3; m++){
        for(n = 0; n < 4; n++){
            printf("%d ", array[m][n]);
        }
        printf("\n");
    }
}

int main()
{
    int array[3][4] = {{11, 12, 13, 14},
                        {15, 16, 17, 18}, 
                        {19, 20, 21, 22}};
    
    disp_array(array);

    return 0;
}

