#include <stdio.h>
#include <stdlib.h>
#define min(a, b) (a<b ? a:b)

// 二分累乗
long lPow (int n, int m) {
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
// グラフを初期化
void InitGraph (int N, long **graph) {
    long INF = lPow(10, 8);
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }
}
// グラフを構築
void makeGraph(int node1, int node2, long **graph) {
    graph[node1][node2] = 1;
    graph[node2][node1] = 1;
}
// ワーシャルフロイド法
void WFmethod (int N, long **graph) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            for (size_t k = 0; k < N; k++) {
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
}
// 距離を取得
void getDistance (int N, int start, long *dist, long **graph) {
    // 始点から各点への距離を取得
    for (size_t i = 0; i < N; i++) {
        dist[i] = graph[start][i];
    }
}
// 最短経路の数を計算
void calcShortestRoutes (int N, int start, int goal, long **graph, long *dist, long *dp) {
    long Mod = lPow(10, 9)+7;
    // 動的計画法
    dp[0] = 1;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (dist[i] == dist[j]+1) {
                dp[i] += dp[j];
                dp[i] = dp[i]%Mod;
            }
        }
    }
    printf("%ld\n", dp[goal]%Mod);


}

// メイン
int main(int argc, char const *argv[]) {
    // 変数
    int N, start, goal, M;
    long **graph;
    // 入力
    scanf("%d %d %d %d", &N, &start, &goal, &M);
    start --; goal--;
    graph = (long **)malloc(sizeof(long *)*N);
    for (size_t i = 0; i < N; i++) {
        graph[i] = (long *)malloc(sizeof(long)*N);
    }
    // グラフを構築
    int node1, node2;
    InitGraph(N, graph);
    for (size_t i = 0; i < M; i++) {
        scanf("%d %d", &node1, &node2);
        node1--; node2--;
        makeGraph(node1, node2, graph);
    }
    // ワーシャルフロイド法
    WFmethod(N, graph);
    // 始点から終点までの距離を取得
    long *dist;
    dist = (long *)malloc(sizeof(long)*N);
    getDistance(N, start, dist, graph);
    // 最短経路の数を計算
    long *dp;
    dp = (long *)malloc(sizeof(long)*N);
    calcShortestRoutes(N, start, goal, graph, dist, dp);

    // メモリ解放
    free(graph); free(dist);
    return 0;
}
