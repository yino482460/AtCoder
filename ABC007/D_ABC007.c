#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max_digit 20
// DPの初期化
long dp[Max_digit][2][2];  // dp[][0]は制限あり, dp[][1]は制限無し
// 桁DP
long digitDP (char num[]) {
    // 初期化
    memset(dp, 0, sizeof(dp));
    // 始まり
    dp[0][0][0] = 1; dp[0][0][1] = 0;
    dp[0][1][0] = 0; dp[0][1][1] = 0;
    int N = strlen(num); // 桁数
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                int x = j ? 9:(num[i] - '0'); // 1のとき9
                //printf("i, %d, j, %d, k %d, x %d\n", i,  j, k, x );
                for (int d = 0; d <= x; d++) {
                    dp[i+1][j || d<x][k || d==4 || d==9] += dp[i][j][k];
                    //printf("dp[1][1][1] %ld\n", dp[1][1][1] );
                }
            }
        }
    }
    long ans = dp[N][1][1] + dp[N][0][1];;
    //printf("dp[N][1][1] + dp[N][0][1] %ld\n", ans );
    return ans;
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
