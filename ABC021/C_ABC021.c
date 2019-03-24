#include <stdio.h>
#include <stdlib.h>
// 始点からの距離
typedef struct que {
    int node;
    long distance;
    int exist;
} que_t;
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
void InitGraph (int N, int **graph) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            graph[i][j] = 0;
        }
    }
}
// グラフを構築
void makeGraph(int node1, int node2, int **graph) {
    graph[node1][node2] = 1;
    graph[node2][node1] = 1;
}
// 各ノードの始点からの距離を設定
void InitDist (int N, int start, long *dist) {
    for (size_t i = 0; i < N; i++) {
        dist[i] = lPow(10, 9);
    }
    dist[start] = 0;
}
// キューを初期化
void InitQue (int N, que_t *que) {
    for (size_t i = 0; i < N; i++) {
        que[i].exist = 0;
    }
}
// キューに距離をセット
void setQueDist (int no, que_t *que, int node, long distance) {
    que[no].node = node;
    que[no].distance = distance;
    que[no].exist = 1;
}
// x番目のキューから削除
void deleteQue (int x, que_t *que) {
    que[x].exist = 0;
}
// キューを交換
void swapQue (que_t *a, que_t *b) {
    que_t tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
// キューにプッシュ
void pushQue (int node, int distance, que_t *que) {
    int n = 0;
    while (que[n].exist != 0) {
        n++;
    }
    setQueDist(n, que, node, distance);
    // 新規ノードが条件を満たすまで
    while (n != 0) {
        int parent = (n-1)/2; // 親の番号
        // 距離が小さくなるように親と子を入れ替え
        if (que[parent].distance > que[n].distance) {
            swapQue(&que[n], &que[parent]);
        }
        n = parent;
    }
}
// キューからポップ
que_t popQue (que_t *que) {
    int n  = 0; // データ数
    while (que[n].exist != 0) {    // 配列の末尾を探す
        n++;
    }
    int last = n-1;
    //printf("before node[0]:node %d, distance %ld\n", que[0].node, que[0].distance);
    que_t pop = que[0];    // 取り出すデータ
    que[0] = que[last];   // 最後尾を一番上に
    //printf("after  node[0]:node %d, distance %ld\n", que[0].node, que[0].distance);
    for (int i = 0, child; (child=2*i+1) < n; ) {
        // 左と右を比較して右が小さければ右を上に
        if ((child != last) && (que[child].distance > que[child+1].distance)) {
            child++;
        }
        // 子と値を入れ替え
        if (que[i].distance > que[child].distance) {
            swapQue(&que[i], &que[child]);
        }
        i = child;
    }
    deleteQue(last, que);
    return pop;
}
// 動的計画法を初期化
void InitDP (int N, long *dp) {
    for (size_t i = 0; i < N; i++) {
        dp[i] = 0;
    }
}

// ダイクストラ法
void Dijkstra (int N, int start, int goal, int **graph) {
    long *dist;
    dist = (long *)malloc(sizeof(long)*N);
    InitDist(N, start, dist);  // 距離を初期化
    // キュー
    que_t *que;
    que = (que_t *)malloc(sizeof(que_t)*N);
    InitQue(N, que);    // キューを初期化
    setQueDist(0, que, start, 0);    // スタートを0に設定
    long cost = 1;  // 次のノードに移動するコスト
    // ダイクストラ
    while (que[0].exist != 0) {
        que_t buf = popQue(que);
        int v = buf.node;
        for (int i = 0; i < N; i++) {
            if (graph[v][i] != 0) { // 接続しているか
                if (dist[i] > dist[v]+cost) {   // 最短経路となる可能性があるか
                    dist[i] = dist[v]+cost;
                    pushQue(i, dist[i], que);
                }
            }
        }
    }
    // 動的計画法
    InitQue(N, que);
    for (int i = 0; i < N; i++) { // 距離順にヒープソート
       pushQue(i, dist[i], que);
    }
   printf("\n");
   // デバッグ push は正常
   for (int i = 0; i < N; i++) {
       printf("que[%d]:node %d, distance %ld\n", i, que[i].node, que[i].distance);
       //printf("dist[%d]:%ld ", i, dist[i]);
       //que_t V = popQue(que);
       //int v = V.node;
      // printf("pop:v %d\n", v);
   }
   printf("\n");
   long *dp, Mod;
    dp = (long *)malloc(sizeof(long)*N);
    InitDP(N, dp);
    dp[start] = 1;
    Mod = lPow(10, 9)+7;
    while (que[0].exist != 0) {
        que_t V = popQue(que);
        int v = V.node;
        //printf("v %d\n", v);
        for (int i = 0; i < N; i++) {
            if (dist[i] == dist[v]+cost) {
                dp[i] += dp[v];
                dp[i] = dp[i]%Mod;
            }
        }
    }
    // 確認
    for (int i = 0; i < N; i++) {
        printf("dist[%d], %ld dp[%d]:%ld\n", i, dist[i], i ,dp[i]);
    }
    printf("\n");
    printf("ans %ld\n", dp[goal]);
    // メモリ解放
    free(dist);
    free(que);
    free(dp);
}

// メイン
int main(int argc, char const *argv[]) {
    // 変数
    int N, start, goal, M;
    int **graph;
    // 入力
    scanf("%d %d %d %d", &N, &start, &goal, &M);
    start --; goal--;
    graph = (int **)malloc(sizeof(int *)*N);
    for (size_t i = 0; i < N; i++) {
        graph[i] = (int *)malloc(sizeof(int)*N);
    }
    // グラフを構築
    int node1, node2;
    InitGraph(N, graph);
    for (size_t i = 0; i < M; i++) {
        scanf("%d %d", &node1, &node2);
        node1--; node2--;
        makeGraph(node1, node2, graph);
    }
    // ダイクストラ法
    Dijkstra(N, start, goal, graph);
    // メモリ解放
    free(graph);
    return 0;
}
