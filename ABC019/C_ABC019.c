#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define swap(a, b) (a+=b, b=a-b, a-=b)
// ソート
void quicksort (int left, int right, int a[]) {
    int pivot = a[(left+right)/2];
    int i = left, j = right;
    // ソート
    while (1) {
        while (a[i]  < pivot ) { i++; }
        while (a[j] > pivot ) { j--; }
        if (i >= j) {   // 終了条件
            break;
        }
        swap(a[i], a[j]);
        i++; j--;
    }
    if (left < i-1) {
        quicksort(left, i-1, a);
    }
    if (j+1 < right) {
        quicksort(j+1, right, a);
    }
}
// 奇数になるまで割り算実行
int divToOdd (int num) {
    while (num%2 == 0) {
        num = num/2;
    }
    return num;
}
// 重複しない数をカウント
void countUnipue (int N, int a[]) {
    for (size_t i = 0; i < N; i++) {
        a[i] = divToOdd(a[i]);
    }
    // 数列を昇順にソート
    quicksort(0, N-1, a);
    // デバッグ
    /*
    for (size_t i = 0; i < N; i++) {
        printf("%2d", a[i]);
    }
    printf("\n");
    */
    // 重複していない数をカウント
    int cnt = 1;
    int now = a[0];
    for (size_t i = 1; i < N; i++) {
        if (now != a[i]) {
            cnt++;
        }
        now = a[i];
    }
    printf("%d\n", cnt);
}

int main(int argc, char const *argv[]) {
    // 変数
    int N;
    int *a;
    // 入力
    scanf("%d", &N);
    a = (int *)malloc(sizeof(int)*N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    // 処理
    countUnipue(N, a);
    // メモリ解放
    free(a);
    return 0;
}
