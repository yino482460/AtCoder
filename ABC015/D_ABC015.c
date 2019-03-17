#include <stdio.h>
#define max(a, b) (a>b ? a:b)
// 変数
int width[51], importance[51];
int dp[10001][51][51];  // 動的計画法配列
int W, N, K;
// 配列の初期化
void InitDp( ) {
    for (size_t i = 0; i < W; i++) {
        for (size_t j = 0; j < N; j++) {
            for (size_t k = 0; k < K; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
}
// 動的計画法
void DP () {
    int maxValue = 0;
    // 配列の初期化
    InitDp();
    dp[0][0][0] = 0;
    for (int i = 0; i <= W; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= K; k++) {
                int next = dp[i][j][k];
                if (i-width[k-1] >= 0) {
                    printf("call DPif\n");
                    printf("i-width[k-1] %d\n", i-width[k-1]);
                    printf("i:%d j:%d k:%d\n", i, j, k);
                    int previous = dp[i-width[k-1]][j-1][k-1] + importance[k-1];
                    maxValue = max(previous, next);
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
