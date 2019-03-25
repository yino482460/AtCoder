#include <stdio.h>
// swap
void swap (int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// qsort
void Qsort (int left, int right, int A[]) {
    int pivot = A[(left+right)/2];
    int i = left, j = right;
    // 無限ループ
    while (1) {
        while (A[i] < pivot) { i++; }
        while (A[j] > pivot) { j --; }
        if (i >= j) {
            //printf("break !\n");
            break;
        }
        swap(&A[i], &A[j]);
        i ++; j--;
    }
    if (left < i-1) {
        Qsort(left, i-1, A);
    }
    if (j+1 < right) {
        Qsort(j+1, right, A);
    }
}
// 重複した数をカウント
void countVariety (int N, int A[]) {
    //printf("call countVariety\n");
    Qsort(0, N-1, A);
    int cnt = 0;
    for (size_t i = 0; i < N; i++) {
        if (A[i] == A[i+1]) {
            cnt ++;
        }
    }
    printf("%d\n", cnt);
}

int main(int argc, char const *argv[]) {
    // 変数
    int N;
    scanf("%d", &N);
    int A[N];
    // 入力
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    // 出力
    countVariety(N, A);
    return 0;
}
