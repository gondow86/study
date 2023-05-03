#include <stdio.h>

int main()
{
    int input;
    int input_copy;
    int first;
    int second;
    int third;
    int fourth;
    printf("input an integer:");
    scanf("%d", &input);
    input_copy = input;
    first = input / 1000;
    input -= first * 1000;
    second = input / 100;
    input -= second * 100;
    third = input / 10;
    input -= third * 10;
    fourth = input;
    if(input_copy < 10000 && input_copy >= 0){
        if(first == 0){
            if(second == 0){
                if(third == 0){
                    if(fourth == 0){
                        printf("%d = %d\n", input_copy, fourth);
                    } else{
                        printf("%d = %d\n", input_copy, fourth);
                    }

                } else{
                    if(fourth == 0){
                        printf("%d = %d × 10\n", input_copy, third);
                    } else{
                        printf("%d = %d × 10 + %d\n", input_copy, third, fourth);
                    }

                }

            } else{
                if(third == 0){
                    if(fourth == 0){
                        printf("%d = %d × 100\n", input_copy, second);
                    } else{
                        printf("%d = %d × 100 + %d\n", input_copy, second, fourth);
                    }

                } else{
                    if(fourth == 0){
                        printf("%d = %d × 100 + %d × 10\n", input_copy, second, third);
                    } else{
                        printf("%d = %d × 100 + %d × 10 + %d\n", input_copy, second, third, fourth);
                    }

                }

            }

        } else{
            if(second == 0){
                if(third == 0){
                    if(fourth == 0){
                        printf("%d = %d × 1000\n", input_copy, first);
                    } else{
                        printf("%d = %d × 1000 + %d\n", input_copy, first, fourth);
                    }

                } else{
                    if(fourth == 0){
                        printf("%d = %d × 1000 + %d × 10\n", input_copy, first, third);
                    } else{
                        printf("%d = %d × 1000 + %d × 10 + %d\n", input_copy, first, third, fourth);
                    }

                }

            } else{
                if(third == 0){
                    if(fourth == 0){
                        printf("%d = %d × 1000 + %d × 100\n", input_copy, first, second);
                    } else{
                        printf("%d = %d × 1000 + %d × 100 + %d\n", input_copy, first, second, fourth);
                    }

                } else{
                    if(fourth == 0){
                        printf("%d = %d × 1000 + %d × 100 + %d × 10\n", input_copy, first, second, third);
                    } else{
                        printf("%d = %d × 1000 + %d × 100 + %d × 10 + %d\n", input_copy, first, second, third, fourth);
                    }

                }

            }

        }
    } else{
        printf("Incorrect input.\n");
    }
    return 0;
}