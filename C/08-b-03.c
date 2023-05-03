#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    char sign;
    int sen;
    int hyaku;
    int ju;
    int ichi;

    scanf("%d", &num);

    if(abs(num) > 9999){
        printf("Input range is -9999 to 9999\n");
        return 0;
    }

    if(num < 0){
        sign = '-';
        num = num * -1;
    }
    
    switch (sign){
        case '-':
            printf("minus ");
            break;
        
        default:
            break;
    }

    sen = num / 1000;
    hyaku = (num / 100) - (sen * 10);
    ju = (num / 10) - (sen * 100 + hyaku * 10);
    ichi = num - (sen * 1000 + hyaku * 100 + ju * 10);

    switch (sen)
    {
        case 0:
            break;

        case 1:
            printf("sen ");
            break;
        
        case 2:
            printf("ni sen ");
            break;
        
        case 3:
            printf("san zen ");
            break;

        case 4:
            printf("yon sen ");
            break;

        case 5:
            printf("go sen ");
            break;

        case 6:
            printf("roku sen ");
            break;

        case 7:
            printf("nana sen ");
            break;

        case 8:
            printf("hattu sen ");
            break;

        case 9:
            printf("kyu sen ");
            break;

        default:
            break;
    }

    switch (hyaku)
    {
        case 0:
            break;
        
        case 1:
            printf("hyaku ");
            break;

        case 2:
            printf("ni hyaku ");
            break;

        case 3:
            printf("san byaku ");
            break;

        case 4:
            printf("yon hyaku ");
            break;

        case 5:
            printf("go hyaku ");
            break;

        case 6:
            printf("rottu pyaku ");
            break;

        case 7:
            printf("nana hyaku ");
            break;

        case 8:
            printf("hattu pyaku ");
            break;

        case 9:
            printf("kyu hyaku ");
            break;

        default:
            break;
    }

    switch (ju)
    {
    case 0:
        break;
    
    case 1:
        printf("ju ");
        break;

    case 2:
        printf("ni ju ");
        break;

    case 3:
        printf("san ju ");
        break;

    case 4:
        printf("yon ju ");
        break;

    case 5:
        printf("go ju ");
        break;

    case 6:
        printf("roku ju ");
        break;

    case 7:
        printf("nana ju ");
        break;

    case 8:
        printf("hachi ju ");
        break;

    case 9:
        printf("kyu ju ");
        break;

    default:
        break;
    }

    switch (ichi)
    {
    case 0:
        printf("zero");
        break;
    
    case 1:
        printf("ichi");
        break;

    case 2:
        printf("ni");
        break;

    case 3:
        printf("san");
        break;

    case 4:
        printf("yon");
        break;

    case 5:
        printf("go");
        break;

    case 6:
        printf("roku");
        break;

    case 7:
        printf("nana");
        break;
    
    case 8:
        printf("hachi");
        break;

    case 9:
        printf("kyu");
        break;

    default:
        break;
    }
    printf("\n");

    return 0;
}