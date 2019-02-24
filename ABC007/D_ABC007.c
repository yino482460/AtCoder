#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max_digit 18
// DPの初期化
long dp[Max_digit][2][2];  // dp[][0]は制限あり, dp[][1]は制限無し
// 桁DP
long digitDP (char A[]) {
    // 始まり
    dp[0][0][0] = 1;
    int N = strlen(A); // 桁数
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                int x = j ? (A[i] - '0'):9; // 1のとき9
                for (int d = 0; d <= x; d++) {
                    dp[i + 1][j || d < x][k || d == 4 || d == 9] += dp[i][j][k];
                }
            }
        }
    }
    return dp[N][1][1] + dp[N][0][1];
}


int main(int argc, char const *argv[]) {
    // 変数
    long a,b;
    char A[Max_digit+1], B[Max_digit+1];
    scanf("%ld %ld", &a, &b);
    // 文字列に変換
    a = a-1;
    snprintf(A, Max_digit+1, "%ld", a);
    snprintf(B, Max_digit+1, "%ld", b);
    // 出力
    long ans = digitDP(B) - digitDP(A);
    printf("%ld\n", ans );
    return 0;
}
