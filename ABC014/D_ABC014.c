#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// list
typedef struct list_t {
    int size;   // 繋がっているノードの数
    int node;   // 連結しているノードの値
    struct list_t *previous;    // 1つ前に繋げたノード
    struct list_t *latest;
} list_t;
// 木を表す構造体
typedef struct tree_t {
    int parent;  // 親ノード, 根 = NULL
    int value;  // ノード自身の値
    int depth;  // ルートからの深さ
} tree_t;

// ノードの初期化
void InitNode (int N, list_t node[]) {
    for (size_t i = 0; i < N; i++) {
        node[i].size = 0;
        node[i].previous = NULL;
        node[i].latest = NULL;
    }
}
// ノード同士の連結状態を構築する
// 入力順と逆順に追加 ここが肝
void conectNode (int i, int newnode, list_t node[]) {
    list_t *new;
    new = (list_t*)malloc(sizeof(list_t));  // 新規メモリの確保
    new->size = node[i].size + 1 ;
    new->node = newnode;
    new->previous = node[i].latest;
    node[i].latest = new;
}
// ノード同士の繋がりを構築する関数
void  strructEdge (int node1, int node2, list_t node[]) {
    // vector的なので最後に値を追加
    conectNode(node1, node2, node);
    conectNode(node2, node1, node);
}
// 木構造を構築する関数 深さ優先探索
void MakeTree (int v, int p ,int d, list_t node[], tree_t tree[]) {
    //ノードvの親 = p
    tree[v].parent = p;
    //ルートからノードvまでの深さ = d
    tree[v].depth = d;
    list_t *nodev = node[v].latest;
    int size = nodev->size;
    for (size_t i = 0; i < size; i++) {
        while ( nodev->previous != '\0' ) {
            if (nodev->node != p) {
                int newv = nodev->node;
                MakeTree(newv, v, d+1, node, tree);
            }
            nodev = nodev->previous;
        }
    }
}
//uとvのLCAを求める
int LCA (int u, int v, tree_t tree[]) {
    int depthu, depthv;
    depthu = tree[u].depth;
    depthv = tree[v].depth;
    //uとvそれぞれのrootからの深さを揃える
    while (depthu > depthv) { u = tree[u].parent; } // uを一つ上に
    while (depthv > depthu) { v = tree[v].parent; }
    //最小祖先ノードで合流するまで１つ１つ向かっていく
    while (u != v) {
        u = tree[u].parent;
        v = tree[v].parent;
    }
    return u;
}



int main(int argc, char const *argv[]) {
    int N;
    scanf("%d", &N);
    // ノードとその連結状態を構築
    list_t *node = (list_t*)malloc(sizeof(list_t)*N);
    InitNode(N, node);
    for (size_t i = 0; i < N-1; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        node1 = node1-1; node2 = node2-1;
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
        a = a-1; b = b-1;
        int lca = LCA(a, b, tree);
        int ans = tree[a].depth + tree[b].depth - 2*tree[lca].depth +1;
        printf("%d\n", ans);
    }
    return 0;
}
