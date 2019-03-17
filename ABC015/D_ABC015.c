#include <stdio.h>
#define max(a, b) (a>b ? a:b)
// 変数
int weight[51], importance[51];
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
int DP (int useW, int useN, int now) {
    int maxValue = 0;
    // 配列の初期化
    InitDp();
    // dp[0][0][0] ={{{0}}};
    for (size_t i = 0; i < W; i++) {
        for (size_t j = 1; j < N; j++) {
            for (size_t k = 1; k < K; k++) {
                int next = dp[i][j][k];
                int previous = dp[i-weight[i]][j-1][k-1] + importance[k-1];
                maxValue = max(previous, next);
            }
        }
    }

    return maxValue;
}

int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d %d %d", &W, &N, &K);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &weight[i], &importance[i]);
    }

    return 0;
}
