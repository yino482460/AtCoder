#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define size 100000
// 変数
int N;
int H[size], S[size];
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
// あるペナルティーでの制限時間での成功判定
bool check (long Opt) {
    double t[N];    //風船が割れるまでの時間
    for (size_t i = 0; i < N; i++) {
        if ((Opt - H[i]) < 0) {
            return false;
        } else {
            t[i] = (Opt - H[i])/S[i];
        }
    }
    // ソート
    quicksort(0, N-1, t);
    // 判定
    for (int i = 0; i < N; i++) {
        if (t[i] < i) {
            return false;
        }
    }
    return true;
}
// 二分検索
void binarySearch ( ) {
    long left, right;
    left = 0; right = LONG_MAX;
    // 探索
    while (left+1 < right) {
        long mid = (left+right)/2;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    printf("%ld\n", right);
}

// メイン
int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &H[i], &S[i]);
    }
    // 出力
    binarySearch();
    return 0;
}
