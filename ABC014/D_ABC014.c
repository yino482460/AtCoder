#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 可変長ノード構造体
typedef struct vector {
    int size;


} vec_t;
// ノードを表す構造体
typedef struct node_t {
    struct node_t *parent;  // 親ノード, 根 = NULL
    int value;  // ノード自身の値
    int depth;  // ルートからの深さ
    struct node_t *child;   // 最初に連結する子ノード
    struct node_t *next;   // 自分の隣のノード 単独ならNULL
} node_t;
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
// 木構造を構築する関数
void  MakeTree (int node1, int node2, node_t node[]) {
    node[node1].value = node1;
    node[node2].value = node2;
    // vector的なので最後に値を追加

}


int main(int argc, char const *argv[]) {
    int N;
    scanf("%d", &N);
    node_t *node = (node_t*)malloc(sizeof(node_t)*N);
    for (size_t i = 0; i < N-1; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        node1 = node1-1; node2 = node2-1;
        MakeTree(node1, node2, node);
    }



    return 0;
}
