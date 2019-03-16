#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Log 17
#define swap(a, b) (a+=b, b=a-b, b=a-b)
// list
typedef struct list_t {
    int size;   // 繋がっているノードの数
    int node;   // 連結しているノードの値
    struct list_t *previous;    // 1つ前に繋げたノード
    struct list_t *latest;
} list_t;
// 木を表す構造体
typedef struct tree_t {
    int parent[Log];  // 親ノード, 根 = NULL
    int value;  // ノード自身の値
    int depth;  // ルートからの深さ
} tree_t;

// ノードの初期化
void InitNode (int N, list_t node[]) {
    for (size_t i = 0; i < N; i++) {
        node[i].size = 0;
        node[i].previous = NULL;
        node[i].latest = &node[i];
    }
}
// ノード同士の連結状態を構築する
// 入力順と逆順に追加 ここが肝
void conectNode (int i, int newnode, list_t node[]) {
    list_t *nnew;
    nnew = (list_t*)malloc(sizeof(list_t));  // 新規メモリの確保
    nnew->size = (node[i].latest) -> size + 1 ;
    nnew->node = newnode;
    nnew->previous = node[i].latest;
    node[i].latest = nnew;
}
// ノード同士の繋がりを構築する関数
void  strructEdge (int node1, int node2, list_t node[]) {
    // vector的なので最後に値を追加
    conectNode(node1, node2, node);
    conectNode(node2, node1, node);
}

// 木構造を構築する関数 深さ優先探索 lognバージョンの肝
void DFS (int v, int p ,int d, list_t node[], tree_t tree[]) {
    tree[v].value = v;
    //ノードvの親 = p 2^i回上回った時のノード
    tree[v].parent[0] = p;  // 一つ上の親
    //ルートからノードvまでの深さ = d
    tree[v].depth = d;
    list_t *nodev = node[v].latest; // 最も最近追加されたノードに移動
    int size = nodev->size;
    for (size_t i = 0; i < size; i++) {
        while (nodev->previous != '\0' ) {
            if (nodev->node != p) {
                int newv = nodev->node;
                DFS(newv, v, d+1, node, tree);
            }
            nodev = nodev->previous;
        }
    }
}
// 木構造を高速で構築するO(log n) ver
void MakeTree (int v, int p ,int d, list_t node[], tree_t tree[]) {
    DFS(0, -1, 0, node, tree);
    for (size_t i = 0; i+1 < Log; i++) {
        // ダブリング
        if (tree[v].parent[i] < 0) {
            //ノードvの2^iの親が存在しない場合いくら辿っても存在しない
            tree[v].parent[i+1] = -1;
        } else {
            // ダブリング
            tree[v].parent[i+1] = tree[tree[v].parent[i]].parent[i];
        }
    }
}

//uとvのLCAを求める
int LCA (int log, int u, int v, tree_t tree[]) {
    if (tree[u].depth > tree[v].depth) { swap(u, v); }
    //この時点ではdepth[v] >= depth[u]が成り立つ

    //uとvが同じ深さになるまで親ノードを上る
    for(int i = 0;i < log; i++){
        if( ((tree[v].depth - tree[u].depth) >> i & 1) == 1){
            v = tree[v].parent[i];
        }
    }
    // uが最小祖先の場合
    if (u == v) {
        return u;
    }
    //uとvをそれぞれ親方向に上る
    for(int i = log - 1;i >= 0;i--){
        if(tree[u].parent[i] != tree[v].parent[i]){
            u = tree[u].parent[i];
            v = tree[v].parent[i];
        }
    }
    int lca = tree[u].parent[0];    // 最小共通祖先
    return lca;
}
// Debug
void Debug (int N,tree_t tree[]) {
    printf("call debug\n");
    for (size_t i = 0; i < N; i++) {
        int p = tree[i].parent[0];
        int v = tree[i].value;
        int d = tree[i].depth;
        printf("v;%2d p:%2d d:%2d \n", v, p, d);
    }
}

// Main
int main(int argc, char const *argv[]) {
    int N;
    int log = 0;
    scanf("%d", &N);
    // 前処理
    while((1 << log) < N){
        log++;
    }
    // ノードとその連結状態を構築
    list_t *node = (list_t*)malloc(sizeof(list_t)*N);
    InitNode(N, node);
    for (size_t i = 0; i < N-1; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        node1--; node2--;
        strructEdge(node1, node2, node);
    }
    // 木を構築
    tree_t *tree = (tree_t*)malloc(sizeof(tree_t)*N);
    MakeTree(0, -1, 0, node, tree);
    int Q;
    scanf("%d", &Q);
    for (size_t i = 0; i < Q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a --; b --;
        int lca = LCA(log, a, b, tree);  // LCA
        int ans = tree[a].depth + tree[b].depth - 2*tree[lca].depth +1;
        printf("%d\n", ans);
    }
    //Debug(N, tree);
    // メモリの解放
    free(node);
    free(tree);
    return 0;
}
