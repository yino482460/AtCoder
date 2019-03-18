#include <stdio.h>
#define sizeN 100001
#define min(a, b) (a<b ? a:b)
// 変数
int N, M;
// Imos法
void Imos(int l[], int r[], int s[], int score[]) {
    int totalScore = 0;
    // 始点と終点の設定
    for (size_t i = 0; i < N; i++) {
        score[l[i]] += s[i];
        score[r[i]+1] -= s[i];
        totalScore += s[i];
    }
    // 被覆
    for (size_t i = 0; i <= sizeN; i++) {
        score[i+1] += score[i];
    }
    // 確認
    for (size_t i = 0; i <= 20; i++) {
        printf("%3d ", score[i]);
    }
    printf("\n");
    // 最大値の計算
    int min = 1000000;
    for (size_t i = 0; i <= sizeN; i++) {
        if (score[i] > 0) {
            min = min(min, score[i]);
        } else if (score[i]==0 && score[i+1]>0) {
            min = min(min, score[i]);
        }
    }
    int ans = totalScore - min;
    // 出力
    printf("%d\n", ans);
}
// メイン
int main(int argc, char const *argv[]) {
    int l[sizeN], r[sizeN], s[sizeN], score[sizeN];
    // 入力
    scanf("%d %d", &N, &M);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d %d", &l[i], &r[i], &s[i]);
    }
    // 出力
    Imos(l, r, s, score);
    return 0;
}
