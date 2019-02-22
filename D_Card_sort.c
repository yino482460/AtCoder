#include <stdio.h>
#include <string.h>
#define N_max 30002
#define Infinity 100000
long C[N_max];
long DP[N_max];
// 最長増加数列の長さを計算
int calc_LIS (int N, long C[]) {
    DP[0] = -Infinity;
    // 配列の初期化
    for (size_t i = 1; i <= N; i++) {DP[i] = Infinity;}
    // 最長増加数列
    int length = 0; // 数列の長さ
    int left, right, mid;

    for (int i = 1; i <= N; i++) {
        if (C[i] > DP[length]) {
            DP[length+1] = C[i];
            length ++;  // 数列の長さの更新
        } else {    // 二分検索
            left = 1; right = length; mid = (left+right)/2;
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
        scanf("%ld", &C[i] );
    }

    calc_LIS(N, C);
    // 確認
    printf("\n");
    printf("DP[0] %ld\n", DP[0] );
    for (size_t i = 1; i <= N; i++) {
        printf("%2ld", DP[i] );
    }
    printf("\n");
    // 計算
    /*
    int ans;
    ans = N-calc_LIS(N, C);
    // 出力
    printf("%d\n", ans );
    */
    return 0;
}
