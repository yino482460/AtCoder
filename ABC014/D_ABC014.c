#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// list
typedef struct list_t {
    int size;   // 繋がっているノードの数
    int node;   // 連結しているノードの値
    struct list_t *previous;    // 1つ前のノード
} list_t;
// ノードを表す構造体
typedef struct node_t {
    struct node_t *parent;  // 親ノード, 根 = NULL
    int value;  // ノード自身の値
    int depth;  // ルートからの深さ
    struct node_t *child;   // 最初に連結する子ノード
    struct node_t *next;   // 自分の隣のノード 単独ならNULL
} node_t;

// ノードの初期化
void InitEdge (int N, list_t node[]) {
    for (size_t i = 0; i < N; i++) {
        node[i].size = 0;
        node[i].previous = NULL;
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
        new->size = node[i].size +1 ;
        new->node = i;
        new->previous = &node[i];
        new = &node[i];
    }
}
// ノード同士の繋がりを記憶する関数
void  strructEdge (int node1, int node2, list_t node[]) {
    // vector的なので最後に値を追加
    conectNode(node1, node2, node);
    conectNode(node2, node1, node);
}

// ノードを追加する関数
void addNode (node_t *parent, node_t *newnode, int nodeValue) {
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
        node_t *last = parent -> child;
        while (last -> next == '\0') {
            last = last -> next;    // 隣に移動
        }
        last -> next = newnode;
    }
}



int main(int argc, char const *argv[]) {
    int N;
    scanf("%d", &N);
    list_t *node = (list_t*)malloc(sizeof(list_t)*N);
    InitEdge(N, node);
    for (size_t i = 0; i < N-1; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        node1 = node1-1; node2 = node2-1;
        strructEdge(node1, node2, node);
    }



    return 0;
}
