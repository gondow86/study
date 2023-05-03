#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>

void syracuse(int *result, int n)
{
    int counter = 0;
    while (n > 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
            counter++;
        }
    }
    /* 最後1なのでcounterインクリメント */
    counter++;
    result[0] = n;
    result[1] = counter;

    return;
}

int main()
{
    double dtime;
    int sec, msec;
    struct timeb timebf;
    /* 開始時点 */
    ftime(&timebf);
    sec = timebf.time;
    msec = timebf.millitm;

    int result[2] = {};

    syracuse(result, 3);
    printf("This is result:%d\n", result[0]);
    printf("This is counter:%d\n", result[1]);

    /* 終了時点 */
    ftime(&timebf);
    sec = timebf.time - sec;
    msec = timebf.millitm - msec;
    msec += sec * 1000;
    dtime = (double)msec / 1000;
    printf("実行時間は%f秒です\n", dtime);

    return 0;
}