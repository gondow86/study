#include <stdlib.h>
#include <stdio.h>
#define STUDENT_NUM 3

struct score {
    int id;
    int math;
    int eng;
    int sci;
};

void print_total_average(struct score *element)
{
    int total;

    total = element->eng + element->math + element->sci;   
    printf("student[%d] total: %d, average: %f\n", element->id, total, (float) total / 3);

    return;
}

int main()
{
    int i;
    struct score list[STUDENT_NUM] = {
        {61500001, 90, 72, 55}, 
        {61500002, 82, 77, 85}, 
        {61500003, 65, 91, 73},
    };

    for (i = 0; i < STUDENT_NUM; i++){
        print_total_average(&(list[i]));
    }

    return 0;
}