#include <stdio.h>

int factorial(int n)
{
    if(n == 0){
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int permutation(int m, int n)
{
    if(m < n){
        return 0;
    } else if(m == n){
        return 1;
    } else {
        return factorial(m) / factorial(m - n);
    }
}

int combination(int m, int n)
{
    if(m < n){
        return 0;
    } else if(m == n){
        return 1;
    } else {
        return permutation(m, n) / factorial(n);
    }
}

int main()
{
    int m, n;

    printf("input m and n:");
    scanf("%d %d", &m, &n);
    printf("%dP%d = %d\n", m, n, permutation(m, n));
    printf("%dC%d = %d\n", m, n, combination(m, n));

    return 0;
}