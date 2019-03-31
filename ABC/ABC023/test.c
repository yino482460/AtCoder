#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 100000
// 変数
int N;
int H[size], S[size];
int cnt = 0;
// 二分累乗
long lPow (int n, int m) {
    if (m == 0) {
        return 1;
    } else if (m == 1) {
        return n;
    } else if (m%2 == 0) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return n*lPow(n, m-1);
    }
}
// スワップ
void swap (double *a, double *b) {
    double tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
// 降順ソート
void quicksort (int left, int right, double x[]) {
    double pivot = x[(left+right)/2];
    int i = left, j = right;
    // ソート
    while (1) {
        while (x[i] < pivot ) { i++; }
        while (x[j] > pivot ) { j--; }
        if (i >= j) {
            break;
        }
        swap(&x[i], &x[j]);
        i++; j--;
    }
    if (left < i-1) {
        quicksort(left, i-1, x);
    }
    if (j+1 < right) {
        quicksort(j+1, right, x);
    }
}

int main(int argc, char const *argv[]) {
    double a[5] = {1.2, 4.2, 2.3, 7.1, 3.5};
    quicksort(0, 4, a);
    for (int i = 0; i < 5; i++) {
        printf("%d:%lf\n", i, a[i]);
    }
    return 0;
}
