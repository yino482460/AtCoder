#include <stdio.h>
#include <stdlib.h>
#define min(a, b) (a<b ? a:b)

// 二分累乗
long lPow (long n, long m) {
    if (m == 0) {
        return 1;
    } else if (m == 1) {
        return n;
    } else if (m%2 == 0) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return n*lPow(n, m-1);
    }
}
// 距離の初期化
void InitDist (int N, long **dist) {
    long INF = lPow(10, 9);
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }
    //printf("call InitDist\n");
}
// ワーシャルフロイド法
void WFmethod (int N, long **dist) {
    for (size_t k = 1; k < N; k++) {
        for (size_t i = 1; i < N; i++) {
            for (size_t j = 1; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}
// 閉路の最短経路の探索
void calcShortestRoot (int N, int M) {
    // 隣接行列
    long **dist;
    // メモリ確保
    dist = (long **)malloc(sizeof(long *)*N);
    for (size_t i = 0; i < N; i++) {
        dist[i] = (long *)malloc(sizeof(long)*N);
    }
    int node1, node2;
    long distance;
    InitDist(N, dist);
    for (size_t i = 0; i < M; i++) {
        scanf("%d %d %ld ", &node1, &node2, &distance);
        node1--; node2--;
        dist[node1][node2] = distance;
        dist[node2][node1] = distance;
    }
    // ワーシャルフロイド法
    WFmethod(N, dist);
    // 閉路最短距離を計算
    long INF = lPow(10,9);
    long ans = INF;
    for (size_t i = 1; i < N; i++) {
        for (size_t j = i+1; j < N; j++) {
                ans = min(ans, dist[0][i] + dist[j][0] + dist[i][j]);
        }
    }
    // 出力
    if (ans < INF) {
        printf("%ld\n", ans );
    } else {
        printf("-1\n");
    }
    // メモリ解放
    free(dist);
}

// メイン
int main(int argc, char const *argv[]) {
    // 変数
    int N, M;
    // 入力
    scanf("%d %d", &N, &M);
    // 出力
    calcShortestRoot(N, M);
    return 0;
}
