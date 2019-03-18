#include <stdio.h>
#define sizeF 111111
// 二分累乗
long lPow(int n, int m) {
    if (m == 0) {
        return n;
    } else if (m%2 == 2) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return n*lPow(n, m-1);
    }
}
// 動的計画法
void sapliDP (int N, int M, int flaver[]) {
    int dp[sizeF], sum[sizeF];
    long Mod = lPow(10, 8) + 7; // 割り算
    int  left = 0;
}
// メイン
int main(int argc, char const *argv[]) {
    // N:サプリの数 M:味の数
    int N, M;
    int flaver[sizeF];
    // 入力
    scanf("%d %d", &N, &M);
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &flaver[i]);
        flaver[i]--;    // いる?
    }
    return 0;
}
