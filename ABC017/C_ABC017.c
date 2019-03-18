#include <stdio.h>
#include <limits.h>
#define sizeM 111111
#define min(a, b) (a<b ? a:b)
// 変数
int N, M;
long totalScore = 0;
// Imos法
void Imos(int score[]) {
    // 被覆
    for (size_t i = 0; i < M; i++) {
        score[i+1] += score[i];
    }
    // 最大値の計算
    long min = LONG_MAX;
    for (size_t i = 0; i < M; i++) {
        min = min(min, score[i]);
    }
    // 出力
    long ans = totalScore - min;
    printf("%ld\n", ans);
}

// メイン
int main(int argc, char const *argv[]) {
    int l, r, s, score[sizeM];
    // 入力
    scanf("%d %d", &N, &M);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d %d", &l, &r, &s);
        l --; r--;
        // 始点と終点の設定
        score[l] += s;
        score[r+1] -= s;
        totalScore += s;
    }
    // 出力
    Imos(score);
    return 0;
}
