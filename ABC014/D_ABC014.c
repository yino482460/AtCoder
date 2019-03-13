#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 辺を表す構造体
typedef struct node_t {
    struct node_t *parent;  // 親ノード, 根 = NULL
    int nodeNum;  // ノード自身の番号
    int depth;  // ルートからの深さ
    struct node_t *child;   // 最初に連結する子ノード
    struct node_t *next;   // 自分の隣のノード 単独ならNULL
} node_t;
// ノードを追加する関数
void addNode (int NodeNum, node_t *parent, node_t *newnode) {
    // 新規ノードのメモリを確保
    //node_t *node = (node_t*)malloc(sizeof(node_t));
    newnode -> nodeNum = NodeNum;   // ノードの番号
    newnode -> depth = (parent -> depth) +1;    // ルートからの深さ
    newnode -> parent = parent;    // 新規追加ノードの親ノード
    newnode -> child = NULL;
    newnode -> next = NULL;    // 追加直後は右隣は無し
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



    return 0;
}
