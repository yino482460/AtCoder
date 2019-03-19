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
long divToOdd (long num) {
    while (num%2 == 0) {
        num = num/2;
    }
    return num;
}
// 重複しない数をカウント
void countUnipue (int N, long a[]) {
    long cnt = 0;
    // 数列を降順にソート
    quicksort(0, N-1, a);
    for (size_t i = 0; i < N; i++) {
        a[i] = divToOdd(a[i]);
    }
    // デバッグ用
    for (size_t i = 0; i < N; i++) {
        printf("%2ld", a[i]);
    }
    printf("\n");
    printf("call countUnipue\n");
    /*
    // 重複していない数をカウント
    int left = 0, right = left;
    while (1) {
        if (a[left] != a[right]) {
            cnt++;
        }
        while (a[left] == a[right]) {
            right ++;
        }

        left = right;
        if (right == N) {
            break;
        }
    }
    */
    printf("%ld\n", cnt);
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
    // 処理
    countUnipue(N, a);
    return 0;
}
