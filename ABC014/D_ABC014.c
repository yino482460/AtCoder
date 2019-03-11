#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 辺を表す構造体
typedef struct edge {
    int x;
    int y;
} edge;
// 変数
int N, Q;
int *a, *b;
edge *Edge; //ノード同士の連結
int root; //ルートの番号
int *parent; //親のノード番号
int *depth; //ルートからの深さ
int *conect;    //あるノードがどれだけのノードと繋がっているか
int **tree; // 木構造を保存
// 入力
int InPut (void) {
    scanf("%d", &N);
    Edge = (edge*)malloc(sizeof(edge)*N);
    parent = (int*)malloc(sizeof(int)*N);
    depth = (int*)malloc(sizeof(int)*N);
    conect = (int*)malloc(sizeof(int)*N);
    root = 0;
    int X,Y;
    // ノード同士の連結状態を記憶
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &X, &Y);
        Edge[i].x = X-1; Edge[i].y = Y-1;
        conect[X]++; conect[Y]++;
    }
    // 木構造を構築する配列を用意
    tree = (int**)malloc(sizeof(int*)*N);
    for(int i = 0; i < N; i++){
        tree[i]=(int*)malloc(sizeof(int)*conect[i]);
    }
    // 木構造を構築
    for (size_t i = 0; i < N-1; i++) {
        tree[Edge[i].x][i] = Edge[i].y; // バグ
    }


    // 追加する辺
    scanf("%d", &Q);
    a = (int*)malloc(sizeof(int)*Q);
    b = (int*)malloc(sizeof(int)*Q);
    for (size_t i = 0; i < Q; i++) {
        scanf("%d %d", &a[i]-1, &b[i]-1);
    }
    return 0;
}
// 深さ優先探索
void DFS (int x, int p, int d) {
    // ノードxの親 = p
    parent[x] = p;
    // 根っこ(ルート)からノードxまでの深さ = d
    depth[x] = d;
    for (size_t i = 0; i < conect[x]; i++) {
        /* code */
    }

}
// LCA (n) バージョン
int LCA (void) {


    return 0;
}

int main(int argc, char const *argv[]) {
    InPut();    // 入力



    return 0;
}
