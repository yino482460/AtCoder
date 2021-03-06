#include <stdio.h>
#include <stdlib.h>
long H, W, T;
int sx, sy, gx, gy;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
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
// 関数定義
long lPow(long n, long m);    // 二分累乗
void setBoard (char **s, long **dist);    // 文字を整理
void swapQue (heap_t *a, heap_t *b);   // ノードを交換
void InitDist (int H, int W, long **dist);   // 距離の初期化
void InitQue(int H, int W, heap_t que[]);   // キューの初期化
void addQue (int x, int y, int n, long **dist, heap_t node[]);   // 配列に追加
void deleteQue (int x, heap_t node[]); // 配列から削除
void pushHeap (int x, int y, long **dist, heap_t node[]);  // ヒープ化された配列に要素を追加
heap_t popHeap (heap_t node[]); // ヒープから最小値を取り出し削除する
long Dijkstra (long cost, long **dist, char **s);  // ダイストラクタ法
void BinarySearch (long **dist, char **s);    // 二分検索
//メイン
int main(int argc, char const *argv[]) {
    // 変数
    char **s;
    long **dist;    // 各マス目までの距離
    // 入力
    scanf("%ld %ld %ld\n", &H, &W, &T);
    // メモリ確保
    s = (char **)malloc(sizeof(char *)*H);
    dist = (long **)malloc(sizeof(long *)*H);
    for (size_t i = 0; i < H; i++) {
        s[i] = (char *)malloc(sizeof(char)*(W+1));
        dist[i] = (long *)malloc(sizeof(long)*W);
    }
    // 盤面の入力とスタートとゴールの座標の取得
    setBoard(s, dist);
    // ダイストラクタ法と二分検索
    BinarySearch(dist, s);
    // メモリ解放
    for (size_t i = 0; i < H; i++) {
        free(s[i]); free(dist[i]);
    }
    free(s); free(dist);
    return 0;
}

// 二分累乗
long lPow(long n, long m) {
    if (m == 0) {
        return 1;
    } else if (m == 1) {
        return n;
    } else if (m%2 == 2) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return n*lPow(n, m-1);
    }
}
// 文字整理
void setBoard (char **s, long **dist) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j <= W; j++) {
            scanf("%c", &s[i][j]);
            if (s[i][j] == 'S') {
                sx = j, sy = i; // スタートの座標を記憶
                s[i][j] = '.';
            }
            if (s[i][j] == 'G') {
                gx = j, gy = i; // ゴールの座標を記憶
                s[i][j] = '.';
            }
        }
    }
    //printf("sy %d sx %d gy %d gx %d\n", sy, sx, gy, gx);
}
// ノードを交換
void swapQue (heap_t *a, heap_t *b) {
    heap_t tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
// 距離の初期化
void InitDist(int H, int W, long **dist) {
    // 各マスの距離を無限に設定
    long INF = lPow(10, 10)+lPow(10, 6);
    for (size_t i = 0; i < H; i++) {
        for (size_t j = 0; j < W; j++) {
            dist[i][j] = INF;
        }
    }
    //  スタート地点は0
    dist[sy][sx] = 0;
}
// キューの初期化
void InitQue(int H, int W, heap_t que[]) {
    for (size_t i = 0; i < H*W; i++) {
        que[i].exist = 0;
    }
}
//  座標 x,yの距離を n番目のキューに追加
void  addQue (int x, int y, int n, long **dist, heap_t node[]) {
    node[n].P.x = x;
    node[n].P.y = y;
    node[n].distance = dist[y][x];
    node[n].exist = 1;  // 存在
}
// x番目のキューから削除
void deleteQue (int n, heap_t node[]) {
    node[n].exist = 0;
}
// ヒープ化された配列に要素を追加
void pushHeap (int x, int y, long **dist, heap_t node[]) {
    int n  = 0; // データ数
    while (node[n].exist != 0) {    // 配列の末尾を探す
        n++;
    }
    addQue(x, y, n, dist, node);
    // 新規ノードが条件を満たすまで
    while (n != 0) {
        int parent = (n-1)/2; // 親の番号
        // 距離が小さくなるように親と子を入れ替え
        if (node[parent].distance > node[n].distance) {
            swapQue(&node[n], &node[parent]);
        }
        n = parent;
    }
}
// ヒープから最小値を取り出し削除する
heap_t popHeap (heap_t node[]) {
    int n  = 0; // データ数
    while (node[n].exist != 0) {    // 配列の末尾を探す
        n++;
    }
    int last = n-1;   // ここから下が重要
    heap_t pop = node[0];    // 取り出すデータ
    node[0] = node[last];   // 最後尾を一番上に
    //swapQue(&node[0], &node[last]);
    for (int i = 0, child; (child=2*i+1) < n; i++) {
        // 左と右を比較して右が小さければ右を上に
        if ((child != last) && (node[child].distance > node[child+1].distance)) {
            child++;
        }
        // 子と値を入れ替え
        if (node[i].distance > node[child].distance) {
            swapQue(&node[i], &node[child]);
        }
        i = child;
    }
    deleteQue(last, node);
    return pop;
}

// ダイクストラ法
long Dijkstra (long c, long **dist, char **s) {
    //printf("call Dijkstra\n");
    heap_t *que;
    que = (heap_t *)malloc(sizeof(heap_t)*H*W);
    InitDist(H, W, dist);
    InitQue(H, W, que);
    addQue(sx, sy, 0, dist, que);
    // 本体
    while (que[0].exist != 0) {
        heap_t buf = popHeap(que);  // 探索の起点
        int X = buf.P.x, Y = buf.P.y;
        //printf("que[0] y:%d x:%d\n", Y, X);
        for (size_t i = 0; i < 4; i++) {
            int nx = X+dx[i], ny = Y+dy[i];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) { continue; }
            //printf("ny:%d nx:%d\n", ny, nx);
            long cost = (s[ny][nx]=='.' ? 1L : c);    // 白はコスト1黒はコストc
            //printf("cost %ld\n", cost);
            if (dist[ny][nx] > dist[Y][X] + cost) {
            dist[ny][nx] = dist[Y][X] + cost;
            //printf("goal %ld\n", dist[gy][gx]);
            pushHeap(nx, ny, dist, que);
            }
        }
    }
    // 距離を確認
    /*
    for (size_t i = 0; i < H; i++) {
        for (size_t j = 0; j < W; j++) {
            printf("%3ld ", dist[i][j]);
        }
        printf("\n");
    }
    */
    // メモリ解放
    free(que);
    //printf("sy %d sx %d gy %d gx %d\n", sy, sx, gy, gx);
    return dist[gy][gx];
}
// 二分検索
void BinarySearch(long **dist, char **s) {
    //printf("call BinarySearch\n");
    long low = 1, high = T;
    //printf("T %ld\n", T);
    long maxTime, cost;
    // 二分検索
    while ((high-low) > 1) {
        cost = (low+high)/2;
        //printf("cost %ld\n", cost);
        maxTime = Dijkstra(cost, dist, s);
        //printf("maxTime %ld\n", maxTime);
        if (maxTime > T) {
            high = cost;
        } else {
            low = cost;
        }
        //printf("low %ld high %ld\n", low, high);
    }
    printf("%ld\n", low);
}
