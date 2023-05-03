#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
#define IN 10000000
// untilはwhileで書くと, 確か条件式が逆になることに注意

void syracuse(int a[][2])
{
    int i, n;
    int counter;
    double max, min, t;
    int i_max, i_min, chain_max, chain_min;
    int sum = 0;
    max = -1;
    min = 1000000;

    for (i = 1; i < IN; i++) {
        counter = 0;
        n = 2 * i - 1;
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
        a[i][0] = 2 * i - 1;
        a[i][1] = counter;
        t = (double) 10000 * a[i][1] / i;
        sum += a[i][1];
        if (t > max) {
            i_max = i;
            max = t;
            chain_max = a[i][1];
        } else if(t < min) {
            i_min = i;
            min = t;
            chain_min = a[i][1];
        }
    }
    printf("ave. = %d\n", sum / IN);
    printf("max:%d/%d=%lf, min:%d/%d=%lf\n", chain_max, i_max, max, chain_min, i_min, min);

    return;
}

void insertionsort(int a[][2], int n)
{
    int i, j;
    int w1, w2;
    for (i = 1; i <= n; i++) {
        w1 = a[i][1];
        a[0][1] = w1;
        w2 = a[i][0];
        a[0][0] = w2;
        j = i - 1;
        while (w1 < a[j][1]) {
            a[j + 1][1] = a[j][1];
            a[j + 1][0] = a[j][0];
            j = j - 1;
        }
        a[j + 1][1] = w1;
        a[j + 1][0] = w2;
    }

    return;
}

void quicksort(int a[][2], int n)
{
    struct array {
        int left;
        int right;
    };
    int sp;
    int w1, w2, w3, w4, w5, w6, t, pivot;
    int left, right, center, i, j;
    int limit;   
    struct array stack[41];

    limit = 10;
    sp = 1;
    stack[1].left = 1;
    stack[1].right = n;
    do {
        left = stack[sp].left;
        right = stack[sp].right;
        sp = sp - 1;
        while (right - left >= limit) {
            w1 = a[left][1];
            w2 = a[right][1];
            center = (left + right) / 2;
            w3 = a[center][1];
            w4 = a[left][0];
            w5 = a[right][0];
            w6 = a[center][0];
            a[center][1] = a[left + 1][1];
            // iのswap
            a[center][0] = a[left + 1][0];

            if (w1 > w2) {
                t = w1;
                w1 = w2;
                w2 = t;
                // iのswap
                t = w4;
                w4 = w5;
                w5 = t;
            }
            if (w2 > w3) {
                t = w2;
                w2 = w3;
                w3 = t;
                //iswap
                t = w5;
                w5 = w6;
                w6 = t;
                if (w1 > w2) {
                    t = w1;
                    w1 = w2;
                    w2 = t;
                    //iswap
                    t = w4;
                    w4 = w5;
                    w5 = t;
                }
            }
            a[left][1] = w1;
            a[right][1] = w3;
            a[left + 1][1] = w2;
            // iのswap
            a[left][0] = w4;
            a[right][0] = w6;
            a[left + 1][0] = w5;

            pivot = w2;
            i = left + 1;
            j = right;
            do {
                do {
                    i = i + 1;
                } while (a[i][1] < pivot);
                do {
                    j = j - 1;
                } while (a[j][1] > pivot);
                if (i < j) {
                    t = a[i][1];
                    a[i][1] = a[j][1];
                    a[j][1] = t;

                    // indexも入れ替える
                    t = a[i][0];
                    a[i][0] = a[j][0];
                    a[j][0] = t;
                }
            } while (i < j);
            t = a[left + 1][1];
            a[left + 1][1] = a[j][1];
            a[j][1] = t;
            // indexのswap
            t = a[left + 1][0];
            a[left + 1][0] = a[j][0];
            a[j][0] = t;
            
            /* 追加でspの変域の条件を付与 */
            if (sp < 40) {
                sp = sp + 1;
            }
            if (j - left <= right - j) {
                stack[sp].left = j + 1;
                stack[sp].right = right;
                right = j - 1;
            } else {
                stack[sp].left = left;
                stack[sp].right = j - 1;
                left = j + 1;
            }
        }
    } while (sp > 0);
    // printf("sp:%d\n", sp);

    for (i = 1; i <= n; i++) {
        w1 = a[i][1];
        w2 = a[i][0];
        a[0][1] = w1;
        a[0][0] = w2;
        j = i - 1;
        while (w1 < a[j][1]) {
            a[j + 1][1] = a[j][1];
            a[j + 1][0] = a[j][0];
            j = j - 1;
        }
        a[j + 1][1] = w1;
        a[j + 1][0] = w2;
    }

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

    /* ここにプログラムを入れる */
    int i;
    static int a[IN][2];
    syracuse(a);
    //配列のサイズ-1　で呼び出し
    quicksort(a, IN - 1);
    // insertionsort(a, IN - 1);
    for (i = IN - 1; i > IN - 21; i--) {
        printf("%d:%d\n", a[i][0], a[i][1]);
    }

    /* 終了時点 */
    ftime(&timebf);
    sec = timebf.time - sec;
    msec = timebf.millitm - msec;
    msec += sec * 1000;
    dtime = (double)msec / 1000;
    printf("実行時間は%f秒です\n", dtime);
    
    return 0;
}