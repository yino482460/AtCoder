#include <stdio.h>
#include <stdlib.h>
#define size 102000
// メイン
int main(int argc, char const *argv[]) {
    // 変数
    int R, C, K, N;
    // 入力
    scanf("%d %d %d %d", &R, &C, &K, &N);
    // 変数
    int r[size], c[size];
    int candyInRow[size], candyInColumn[size];
    // 各行または各列にいくつの飴が含まれているか
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &r[i], &c[i]);
        r[i]--; c[i]--;
        candyInRow[r[i]]++;
        candyInColumn[c[i]] ++;
    }
    // ある飴の個数を含む行または列がいくつあるか
    int rowCount[size], columnCount[size];
    for (size_t i = 0; i < R; i++) {
        rowCount[candyInRow[i]]++;
    }
    for (size_t i = 0; i < C; i++) {
        columnCount[candyInColumn[i]]++;
    }
    long ans = 0;
    for (size_t i = 0; i <= K; i++) {
        ans += rowCount[i]*columnCount[K-i];
    }
    // 例外処理
    for (size_t i = 0; i < N; i++) {
        if (candyInRow[r[i]]+candyInColumn[c[i]] == K+1) {
            ans ++;
        }
        if (candyInRow[r[i]]+candyInColumn[c[i]] == K) {
            ans --;
        }
    }
    // 出力
    printf("%ld\n", ans);
    return 0;
}
