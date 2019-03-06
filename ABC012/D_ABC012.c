#include <stdio.h>
#define size_M 44850
#define INF 10000
#define min(a, b) (a<b ? a:b)
#define max(a, b) (a>b ? a:b)
// ワーシャルフロイド法
int WarshallFloyd (int N, int M, int a[], int b[], int t[]) {
    int maxTime = 0;
    int distanse[N+2][N+2]; // 距離行列
    // 距離行列の初期設定
    for (size_t i = 0; i < N+2; i++) {
        for (size_t j = 0; j < N+2; j++) {
            distanse[i][j] = INF;
        }
    }
    // 距離行列の設定
    for (size_t i = 0; i < N; i++) {
        distanse[a[i]][b[i]] = t[i];
        distanse[b[i]][a[i]] = t[i];
    }
    // 最短経路の探索
    for (size_t k = 1; k <= N; k++) {
        for (size_t i = 1; i <= N; i++) {
            for (size_t j = 1; j <= N; j++) {
                distanse[i][j] = min(distanse[i][j], distanse[i][k]+distanse[k][j]);
            }
        }
    }
    // 最悪の探索
    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            maxTime = max(maxTime, distanse[i][j]);
        }
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
