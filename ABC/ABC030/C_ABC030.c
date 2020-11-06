#include <stdio.h>
#include <stdlib.h>
#define A 1
#define B 2
int toA, toB;   // それぞれの空港への所要時間
int *a, *b; // 配列
// 最速で出発できる時間を二分探索
int binSearch (int airport, int stime, int *row) {
    int left, right = 1500000000;
    left = row[0];


}

int main(int argc, char const *argv[]) {
    // 変数
    int N, M;
    // 入力 1
    scanf("%d %d %d %d", &N, &M, &toA, &toB);
    a = (int *)malloc(sizeof(int)*N);
    b = (int *)malloc(sizeof(int)*M);
    //  入力 2
    for (size_t i = 0; i < N; i++) { scanf("%d", &a[i]); }
    for (size_t i = 0; i < M; i++) { scanf("%d", &b[i]); }


    // メモリ解放
    free(a);
    free(b);
    return 0;
}
