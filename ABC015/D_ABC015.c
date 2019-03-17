#include <stdio.h>
#define max(a, b) (a>b ? a:b)
// 変数
int width[51], importance[51];
int dp[10001][51][51];  // 動的計画法配列
int W, N, K;
// 動的計画法
void DP () {
    int maxValue = 0;
    // 配列の初期設定
    dp[0][0][0] = 0;
    for (int w = 0; w <= W; w++) {
        for (int k = 1; k <= K; k++) {
            for (int n = 1; n <= N; n++) {
                int next;
                if (w-width[n-1] >= 0) {
                    //printf("w:%d k:%d n:%d\n", w, k, n);
                    next = dp[w-width[n-1]][k-1][n-1] + importance[n-1];
                    dp[w][k][n] = max(dp[w][k][n-1], next);
                    maxValue = max(dp[w][k][n], maxValue);
                    //printf("dp[w][k][n]:%d maxValue %d\n", dp[w][k][n], maxValue);
                } else {
                    dp[w][k][n] = dp[w][k][n-1];
                }
            }
        }
    }
    printf("%d\n", maxValue);
}

int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d", &W);
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &width[i], &importance[i]);
    }
    // 出力
    DP();
    return 0;
}
