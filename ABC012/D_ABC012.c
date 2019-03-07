#include <stdio.h>
#define size_M 44850
#define INF 10000
#define min(a, b) (a<b ? a:b)
#define max(a, b) (a>b ? a:b)
// ワーシャルフロイド法
int WarshallFloyd (int N, int M, int a[], int b[], int t[]) {
    int maxTime = INF;    // 最善の経路の中の最大
    int distanse[N+5][N+5]; // 距離行列 !要修正
    // 距離行列の初期設定
    for (size_t i = 0; i <= N+1; i++) {
        for (size_t j = 0; j <= N+1; j++) {
            if (i == j) {
                distanse[i][j] = 0;
            } else {
                distanse[i][j] = INF;
            }
        }
    }
    // 距離行列の設定 M=路線の数
    for (size_t i = 0; i < M; i++) {
        distanse[a[i]][b[i]] = t[i];
        distanse[b[i]][a[i]] = t[i];
    }
    // 各最短経路の計算
    for (size_t k = 1; k <= N; k++) {
        for (size_t i = 1; i <= N; i++) {
            for (size_t j = 1; j <= N; j++) {
                distanse[i][j] = min(distanse[i][j], distanse[i][k]+distanse[k][j]);
            }
        }
    }
    // 確認
    for (size_t i = 0; i <= N+1; i++) {
        for (size_t j = 0; j <= N+1; j++) {
            printf("%05d ", distanse[i][j] );
        }
        printf("\n");
    }
    printf("\n");
    // 最短の中の最悪を探索
    for (size_t i = 1; i <= N; i++) {
        int row_max = 0;
        for (size_t j = 1; j <= N; j++) {
            // ある経路の最大値を探索
            row_max = max(row_max, distanse[i][j]);
        }
        maxTime = min(maxTime, row_max);
    }
    return maxTime;
}

int main(int argc, char const *argv[]) {
    // 変数
    int N, M;
    int a[size_M], b[size_M], t[size_M];
    // 入力
    scanf("%d %d", &N, &M);
    for (size_t i = 0; i < M; i++) {
        scanf("%d %d %d", &a[i], &b[i], &t[i]);
    }
    // 出力
    int ans = WarshallFloyd(N, M, a, b, t);
    printf("%d\n", ans );
    return 0;
}
