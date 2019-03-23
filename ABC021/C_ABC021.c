#include <stdio.h>
#include <stdlib.h>
// 辺
typedef struct edge {
    int node1, node2;
} edge_t;
// 始点からの距離
typedef struct node {
    int node;
    long distance;
} node_t;
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
// 各ノードの始点からの距離を設定
void InitDist (int N, node_t *node) {
    for (size_t i = 0; i < N; i++) {
        node[i].distance = lPow(10,9);
    }
}
// ノードに距離をセット
void setNodeDist (int no, long distance, node_t *node) {
    node[no].node = no;
    node[no].distance = distance;
}

// ダイクストラ法
long Dijkstra (int N, int start, int goal, edge_t *edge) {
    long distance = 0;
    node_t *node;
    node = (node_t *)malloc(sizeof(node_t)*N);
    InitDist(N, node);
    setNodeDist(start, 0, node);    // スタートを0に設定
    long cost = 1;

    return distance;
}

int main(int argc, char const *argv[]) {
    // 変数
    int N, start, goal, M;
    edge_t *edge;
    int **graph;
    // 入力
    scanf("%d %d %d %d", &N, &start, &goal, &M);
    edge = (edge_t *)malloc(sizeof(edge_t)*M);
    for (size_t i = 0; i < M; i++) {
        scanf("%d %d", &edge[i].node1, &edge[i].node2);
    }


    return 0;
}
