#include <stdio.h>
#include <string.h>
#define N_max 30002
#define Infinity 10000000
int C[N_max];
long DP[N_max];
// 最長増加数列の長さを計算
int calc_LIS (int N, int C[]) {
    DP[0] = -Infinity;
    int length = 0; // 数列の長さ
    for (size_t i = 1; i <= N; i++) {
        if (C[i] > DP[length]) {
            DP[length+1] = C[i];
            length ++;  // 数列の長さの更新
        } else {    // 二分検索
            int left = 0, right = length, mid = (left+right)/2;
            while (left <= right) {
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
    memset(DP, Infinity, sizeof(DP));
    // 計算
    return 0;
}
