#include <stdio.h>
typedef struct point {
    int x, y;
} point_t;
typedef struct heap {
    point_t P;  // 座標
    int exist; // そのノードに存在するば 1
    int distance;
} heap_t;
// ノードを交換
void swapNode (heap_t *a, heap_t *b) {
    heap_t tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
// ヒープ化された配列に要素を追加
void pushHeap (heap_t newnode, heap_t node[]) {
    int n  = 0; // データ数
    while (node[n].exist != 0) {    // 配列の末尾を探す
        n++;
    }
    // 新規ノードが条件を満たすまで
    while (n != 0) {
        int parent = (n-1)/2; // 親の番号
        // 距離が小さくなるように親と値を入れ替え
        if (node[parent].distance > newnode.distance) {
            swapNode(&newnode, &node[parent]);
        } else {
            break;
        }
        n = parent;
    }
}
// ヒープから要素を取り出す
void popHeap (heap_t node[]) {



}

int main(int argc, char const *argv[]) {
    // 変数

    return 0;
}
