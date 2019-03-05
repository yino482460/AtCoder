#include <stdio.h>
#include <string.h>
#define min(a, b) (a<b ? a:b)
#define INF 100000

void Judge (int N, int NG[]) {
    int DP[310];
    // DPの設定
    for (size_t i = 0; i < N; i++) {
        DP[i] = INF;
    }
    DP[N] = 0;
    // 判定
    for (int i = N; i >= 0; i--) {
        if (i==NG[0] || i==NG[1] || i==NG[2]) {
            continue;
        }
        for (size_t j = 1; j <= 3; j++) {
            DP[i-j] = min(DP[i]+1, DP[i-j]);
        }
    }
    if (DP[0] <= 100) {
        printf("YES\n");   // 成功
    } else {
        printf("NO\n");
    }
}

int main(int argc, char const *argv[]) {
    // 変数
    int N, NG[3];
    // 入力
    scanf("%d", &N );
    for (size_t i = 0; i < 3; i++) {
        scanf("%d", &NG[i]);
        if (N==NG[i]) {
            printf("NO");
            return 0;
        }
    }
    // 出力
    Judge(N, NG);
    return 0;
}
