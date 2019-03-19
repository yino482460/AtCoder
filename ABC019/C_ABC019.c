#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) (a+=b, b=a-b, a-=b)
// ソート
void quicksort (int left, int right, long a[]) {
    long pivot = a[(left+right)/2];
    int i = left, j = right;
    // ソート
    while (1) {
        while (a[i]  > pivot ) { i++; }
        while (a[j] < pivot ) { j--; }
        if (i >= j) {
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

int main(int argc, char const *argv[]) {
    // 変数
    int N;
    long *a;
    // 入力
    scanf("%d", &N);
    a = (long *)malloc(sizeof(long)*N);
    for (size_t i = 0; i < N; i++) {
        scanf("%ld", &a[i]);
    }
    // 計算
    // 確認
    quicksort(0, N-1, a);
    for (size_t i = 0; i < N; i++) {
        printf("%3ld", a[i]);
    }
    printf("\n");

    return 0;
}
