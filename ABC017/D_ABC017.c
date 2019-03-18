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
// 尺取り動的計画法
// dp[i] = 区間 [j, i) が「複数種類のサプリがない」という条件を満たすような j についての dp[j] の総和
void syakutoriDP (int N, int M, int flaver[]) {
    // 味の重複が無いような区間を尺取り法で探索
    int Fvari[M]; // ある区間に種類 i が何個あるか
    int range[N+1];   // 各 i に対する尺取り区間
    int  left = 0;
    for (size_t right = 0; right < N; right++) {
        Fvari[flaver[right]] ++;
        while (left < right && Fvari[right] > 1) {
            Fvari[flaver[left]] --;
            left ++;
        }
        range[right+1] = left;
    }

    int dp[sizeF], sum[sizeF];
    long Mod = lPow(10, 8) + 7; // Mod


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
