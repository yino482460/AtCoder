#include <stdio.h>
#define size 100000
#define swap(a, b) (a+=b, b=a-b, a-=b)
// 変数
int N;
int H[size], S[size];
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
// あるペナルティーでの時間
void check (int Opt) {
    int t[size];    //風船が割れるまでの時間

}

// メイン
int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &H[i], &S[i]);
    }

    return 0;
}
