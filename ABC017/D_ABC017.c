#include <stdio.h>
#define sizeN 111111
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
// 尺取り動的計画法
// dp[i] = 区間 [j, i) が味の重複が無いという条件を満たすような j についての dp[j] の総和
void syakutoriDP (int N, int M, int taste[]) {
    // 味の重複が無いような区間を尺取り法で探索
    int Fvari[M]; // 見ている区間に種類 i が何個あるか
    int range[N+1];   // 各 味 i に対する尺取り区間
    int  left = 0;
    for (int right = 0; right < N; right++) {
        Fvari[taste[right]] ++;
        printf("Fvari %d\n", Fvari[taste[right]]);
        while (left < right && Fvari[taste[right]] > 1) {
            Fvari[taste[left]] --;
            left ++;
        }
        printf("left %d right %d\n", left, right);
        range[right+1] = left;
    }
    // 累積和で高速化
    long dp[sizeN], sum[sizeN];
    long Mod = lPow(10, 8) + 7; // Mod
    dp[0] = 1;
    sum[0] = 0; sum[1] = 1;
    for (int i = 1; i <= N; ++i) {
        dp[i] = (sum[i] - sum[range[i]] + Mod) % Mod; // DP
        sum[i+1] = (sum[i] + dp[i]) % Mod; // 累積
    }
    printf("%ld\n", dp[N]);
}

// メイン
int main(int argc, char const *argv[]) {
    // N:サプリの数 M:味の数
    int N, M;
    int taste[sizeN];
    // 入力
    scanf("%d %d", &N, &M);
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &taste[i]);
        taste[i]--;    // いる?
    }
    // 出力
    syakutoriDP(N, M, taste);
    return 0;
}
