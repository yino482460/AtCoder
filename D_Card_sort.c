#include <stdio.h>
#include <string.h>
#define N_max 30002
#define Infinity 100000
int C[N_max];
int DP[N_max];
// 最長増加数列の長さを計算
int calc_LIS (int N, int C[]) {
    DP[0] = -Infinity;
    // 配列の初期化
    for (size_t i = 1; i <= N; i++) {DP[i] = Infinity;}

    int length = 0; // 数列の長さ
    int left, right, mid;
    // 最長増加数列
    for (int i = 1; i <= N; i++) {
        if (C[i] > DP[length]) {
            DP[length+1] = C[i];
            length ++;  // 数列の長さの更新
        } else {    // 二分検索
            left = 0; right = length; mid = (left+right)/2;
            while (left < right-1) {
                if (C[i] < DP[mid]) {
                    right = mid;
                } else {
                    left = mid;
                }
                mid = (left+right)/2;
            }
            DP[right] = C[i];
        }
    }

    return length;
}

int main(int argc, char const *argv[]) {
    // 変数
    int N;  // カードの枚数
    scanf("%d", &N );
    // 入力
    for (size_t i = 1; i <= N; i++) {
        scanf("%d", &C[i] );
    }
    // 最長部分数列の長さの計算
    calc_LIS(N, C);
    int ans;
    ans = N-calc_LIS(N, C);
    // 出力
    printf("%d\n", ans );
    return 0;
}
