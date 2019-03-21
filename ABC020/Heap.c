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
void  addNode (int x, heap_t newnode, heap_t node[]) {
    node[x].P.x = newnode.P.x;
    node[x].P.y = newnode.P.y;
    node[x].exist = 1;  // 存在
    node[x].distance = newnode.distance;
}
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
        // 右と左の子比較して左の子が小さくなるように
        int left = 2*parent + 1, right = parent*(parent+1);
        if (node[left].distance > node[right].distance) {
            swapNode(&node[left], &node[right]);
        }
        n = parent;
    }
}
// ヒープから最小値を削除する
heap_t popHeap (heap_t node[]) {
    int n  = 0; // データ数
    heap_t pop; // 取り出すデータ
    while (node[n].exist != 0) {    // 配列の末尾を探す
        n++;
    }
    int last = n-1;
    pop = node[last];
    deleteNode(last, node);
    swapNode(&node[0], &node[last]);
    for (int i = 0, child; (child=2*i+1) < n; i++) {
        // 子と値を入れ替え
        /*
        if ((child != last) && (node[i+1].distance < node[i].distance)) {
            child++;
        }
        */
        if (node[i].distance < node[child].distance) {
            swapNode(&node[i], &node[child]);
        }
        i = child;
    }
    return pop;
}

int main(int argc, char const *argv[]) {
    // 変数

    return 0;
}
