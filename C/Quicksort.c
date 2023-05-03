#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
// untilはwhileで書くと, 確か条件式が逆になることに注意

void syracuse()
{
    
}

void quicksort(int a[], int n)
{
    struct array {
        int left;
        int right;
    };
    int sp;
    int w1, w2, w3, t, w, pivot;
    int left, right, center, i, j;
    int limit;   
    struct array stack[40];

    limit = 10;
    sp = 1;
    stack[1].left = 1;
    stack[1].right = n;
    do {
        left = stack[sp].left;
        right = stack[sp].right;
        sp = sp - 1;
        while (right - left >= limit) {
            w1 = a[left];
            w2 = a[right];
            center = (left + right) / 2;
            w3 = a[center];
            a[center] = a[left + 1];
            if (w1 > w2) {
                t = w1;
                w1 = w2;
                w2 = t;
            }
            if (w2 > w3) {
                t = w2;
                w2 = w3;
                w3 = t;
                if (w1 > w2) {
                    t = w1;
                    w1 = w2;
                    w2 = t;
                }
            }
            a[left] = w1;
            a[right] = w3;
            a[left + 1] = w2;
            pivot = w2;
            i = left + 1;
            j = right;
            do {
                do {
                    i = i + 1;
                } while (a[i] < pivot);
                do {
                    j = j - 1;
                } while (a[j] > pivot);
                if (i < j) {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            } while (i < j);
            t = a[left + 1];
            a[left + 1] = a[j];
            a[j] = t;
            /* 追加でspの変域の条件を付与 */
            if (sp <= 40) {
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

    for (i = 1; i <= n; i++) {
        w = a[i];
        a[0] = w;
        j = j - 1;
        while (w < a[j]) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = w;
    }
}

int main()
{

}