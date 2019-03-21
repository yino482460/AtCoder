#include <stdio.h>
#include <stdlib.h>
int H, W, T;
int sx, sy, gx, gy;
// 座標の情報
typedef struct point {
    long x, y;
} point_t;
// ヒープ
typedef struct heap {
    point_t P;  // 座標
    int exist; // 配列に値があれば 1
    int distance;
} heap_t;
long lPow(int n, int m);    // 二分累乗
void setBoard (char **s, long **dist);    // 文字を数字に変換
void swapNode (heap_t *a, heap_t *b);   // ノードを交換
void  addNode (int x, heap_t newnode, heap_t node[]);   // 配列に追加
void deleteNode (int x, heap_t node[]); // 配列から削除
void pushHeap (heap_t newnode, heap_t node[]);  // ヒープ化された配列に要素を追加
heap_t popHeap (heap_t node[]); // ヒープから最小値を取り出し削除する

// ダイストラクタ法
long Dijkstra (int cost, long **dist) {
    heap_t *que;
    que = (heap_t *)malloc(sizeof(heap_t)*H*W);
    que[0].P.x = sx; que[0].P.y = sy;
    que[0].distance = dist[sy][sx];
    que[0].exist = 1;

    // メモリ解放
    free(que);
    return dist[gy][gx];
}


int main(int argc, char const *argv[]) {
    // 変数
    char **s;
    long **dist;    // 各マス目までの距離
    // 入力
    scanf("%d %d %d", &H, &W, &T);
    // メモリ確保
    s = (char **)malloc(sizeof(char *)*H);
    dist = (long **)malloc(sizeof(long *)*H);
    for (size_t i = 0; i < H; i++) {
        s[i] = (char *)malloc(sizeof(char)*(W+1));
        dist[i] = (long *)malloc(sizeof(long)*W);
    }
    // 盤面の入力とスタートとゴールの座標の取得
    setBoard(s, dist);
    // ダイストラクタ法



    // メモリ解放
    free(s); free(dist);
    for (size_t i = 0; i < H; i++) {
        free(s[i]); free(dist[i]);
    }
    return 0;
}


// 二分累乗
long lPow(int n, int m) {
    if (m == 0) {
        return n;
    } else if (m%2 == 2) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return n*lPow(n, m-1);
    }
}
// 文字を数字に変換
void setBoard (char **s, long **dist) {
    // 各マスの距離を無限に設定
    long INF = lPow(10, 10);
    for (size_t i = 0; i < H; i++) {
        for (size_t j = 0; j < (W+1); j++) {
            scanf("%s", &s[i][j]);
            dist[i][j] = INF;
            if (s[i][j] == 'S') {
                sx = j, sy = i;
                s[i][j] = '.';
            }
            if (s[i][j] == 'G') {
                gx = j, gy = i;
                s[i][j] = '.';
            }
        }
    }
    //  スタート地点は0
    dist[sy][sx] = 0;
}
// ノードを交換
void swapNode (heap_t *a, heap_t *b) {
    heap_t tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
// 配列に追加
void  addNode (int x, heap_t newnode, heap_t node[]) {
    node[x] = newnode;
    node[x].exist = 1;  // 存在
}
// 配列から削除
void deleteNode (int x, heap_t node[]) {
    node[x].exist = 0;
}
// ヒープ化された配列に要素を追加
void pushHeap (heap_t newnode, heap_t node[]) {
    int n  = 0; // データ数
    while (node[n].exist != 0) {    // 配列の末尾を探す
        n++;
    }
    addNode(n, newnode, node);
    // 新規ノードが条件を満たすまで
    while (n != 0) {
        int parent = (n-1)/2; // 親の番号
        // 距離が小さくなるように親と子を入れ替え
        if (node[parent].distance > node[n].distance) {
            swapNode(&node[n], &node[parent]);
        }
        n = parent;
    }
}
// ヒープから最小値を取り出し削除する
heap_t popHeap (heap_t node[]) {
    int n  = 0; // データ数
    heap_t pop; // 取り出すデータ
    while (node[n].exist != 0) {    // 配列の末尾を探す
        n++;
    }
    int last = n-1;
    pop = node[last];
    swapNode(&node[0], &node[last]);
    for (int i = 0, child; (child=2*i+1) < n; i++) {
        // 左と右を比較して右が小さければ右を上に
        if ((child != n-1) && (node[child].distance > node[child+1].distance)) {
            child++;
        }
        // 子と値を入れ替え
        if (node[i].distance > node[child].distance) {
            swapNode(&node[i], &node[child]);
        }
        i = child;
    }
    deleteNode(last, node);
    return pop;
}
