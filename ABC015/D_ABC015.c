#include <stdio.h>
#define max(a, b) (a>b ? a:b)
// 変数
int width[51], importance[51];
int dp[10001][51][51];  // 動的計画法配列
int W, N, K;
// 配列の初期化
void InitDp( ) {
    for (size_t i = 0; i < W; i++) {
        for (size_t j = 0; j < K; j++) {
            for (size_t k = 0; k < N; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
}
// 動的計画法
void DP () {
    int maxValue = 0;
    InitDp();
    // 配列の初期設定
    dp[0][0][0] = 0;
    for (int w = 0; w <= W; w++) {
        for (int k = 1; k <= K; k++) {
            for (int n = 1; n <= N; n++) {
                if (w-width[n-1] >= 0) {
                    int next = dp[w][k][n];
                    printf("w:%d k:%d n:%d\n", w, k, n);
                    int previous = dp[w-width[n-1]][k-1][n-1] + importance[n-1];
                    next = max(previous, next);
                    maxValue = max(next, maxValue);
                    printf("maxValue %d\n",maxValue);
                }
            }
        }
    }
    printf("%d\n", maxValue);
}

int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d %d %d", &W, &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &width[i], &importance[i]);
    }
    // 出力
    DP();
    return 0;
}
