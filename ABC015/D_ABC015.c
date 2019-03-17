#include <stdio.h>
#define max(a, b) (a>b ? a:b)
int dp[10001][51][51];  // 動的計画法配列
int W, N, K;

int main(int argc, char const *argv[]) {
    // 変数
    int weight[51], importance[51];
    // 入力
    scanf("%d %d %d", &W, &N, &K);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &weight[i], &importance[i]);
    }

    return 0;
}
