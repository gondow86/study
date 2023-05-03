#include <stdio.h>
#include <stdlib.h>

struct student_data {
    int id;
    int height;
    int weight;
};

int main()
{
    int i;
    int tall_num;
    int short_num;
    int heavy_num;
    int light_num;

    struct student_data list[10];

    for(i = 0; i < 10; i++){
        printf("Input student number, height, weight:");
        scanf("%d %d %d", &(list[i].id), &(list[i].height), &(list[i].weight));
        if (list[i].id < 0){
            break;
        }
        
        if (i > 0 && list[i].height >= list[i - 1].height){ //実行例で~est student number "is"となっているので表示対象は単数と考えて, 同じなら更新とした
            tall_num = i;
        } else if (i > 0 && list[i].height < list[i - 1].height){
            short_num = i;
        }

        if (i > 0 && list[i].weight >= list[i - 1].weight){
            heavy_num = i;
        } else if (i > 0 && list[i].weight < list[i - 1].weight){
            light_num = i;
        }
    }

    printf("Tallest student number is %d (%dcm)\n", list[tall_num].id, list[tall_num].height);
    printf("Shortest student number is %d (%dcm)\n", list[short_num].id, list[short_num].height);
    printf("Heaviest student number is %d (%dkg)\n", list[heavy_num].id, list[heavy_num].weight);
    printf("Lightest student number is %d (%dkg)\n", list[light_num].id, list[light_num].weight);

    return 0;
}