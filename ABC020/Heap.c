#include <stdio.h>
typedef struct point {
    int x, y;
} point_t;
typedef struct heap {
    point_t P;  // 座標
    int exist; // 配列に値があれば 1
    int distance;
} heap_t;
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

int main(int argc, char const *argv[]) {
    // 変数

    return 0;
}
