#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// list
typedef struct list_t {
    int size;   // 繋がっているノードの数
    int node;   // 連結しているノードの値
    struct list_t *previous;    // 1つ前に繋げたノード
    struct list_t *head;
} list_t;
// 木を表す構造体
typedef struct tree_t {
    int parent;  // 親ノード, 根 = NULL
    int value;  // ノード自身の値
    int depth;  // ルートからの深さ
    struct tree_t *child;   // 最初に連結する子ノード
    struct tree_t *next;   // 自分の隣のノード 単独ならNULL
} tree_t;

// ノードの初期化
void InitNode (int N, list_t node[]) {
    for (size_t i = 0; i < N; i++) {
        node[i].size = 0;
        node[i].previous = NULL;
        node[i].head = &node[i];
    }
}
// ノード同士の連結状態を構築する
// 入力順と逆順に追加
void conectNode (int i, int newnode, list_t node[]) {
    list_t *new;
    if (node[i].size == 0) {
        node[i].size ++;
        node[i].node = newnode;
    } else {
        new = (list_t*)malloc(sizeof(list_t));  // 新規メモリの確保
        new->size = node[i].size + 1 ;
        new->node = newnode;
        new->previous = &node[i];
        node[i].head = new;
    }
}
// ノード同士の繋がりを構築する関数
void  strructEdge (int node1, int node2, list_t node[]) {
    // vector的なので最後に値を追加
    conectNode(node1, node2, node);
    conectNode(node2, node1, node);
}
// 木構造を構築する関数
void MakeTree (int v, int p ,int d, list_t node[], tree_t tree[]) {
    //ノードvの親 = p
    tree[v].parent = p;
    //ルートからノードvまでの深さ = d
    tree[v].depth = d;
    int size = node[v].size;
    for (size_t i = 0; i < size; i++) {
        list_t *a = &node[v];
        while ( a->previous == '\0' ) {
            if (a->node != p) {
                int newv = a->node;
                MakeTree(newv, v, d+1, node, tree);
            }
            a = a->previous;
        }
    }
}


// ノードを追加する関数
/*
void addNode (tree_t *parent, tree_t *newnode, int nodeValue) {
    // 新規ノードのメモリを確保
    newnode -> value = nodeValue;
    newnode -> depth = (parent -> depth) +1;
    newnode -> parent = parent;    // 新規追加ノードの親ノード
    newnode -> next = NULL;    // 追加直後は右隣は無し
    newnode -> child = NULL;
    // 親ノードから見た新規ノードとの関係
    if (parent -> child == '\0') {
        parent -> child = newnode;
    } else {
        tree_t *last = parent -> child;
        while (last -> next == '\0') {
            last = last -> next;    // 隣に移動
        }
        last -> next = newnode;
    }
}
*/


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
    // 木を保存する構造体
    tree_t *tree = (tree_t*)malloc(sizeof(tree_t)*N);


    int Q;
    scanf("%d", &Q);
    for (size_t i = 0; i < Q; i++) {
        /* code */
    }



    return 0;
}
