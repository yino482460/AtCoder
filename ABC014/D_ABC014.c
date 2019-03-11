#include <stdio.h>
#include <stdlib.h>
#define X 0
#define Y 1
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
// 入力
int InPut (void) {
    // 入力
    scanf("%d", &N);
    Edge = (edge*)malloc(sizeof(edge)*N);
    parent = (int*)malloc(sizeof(int)*N);
    depth = (int*)malloc(sizeof(int)*N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &Edge[i].x-1, &Edge[i].y-1);
    }
    scanf("%d", &Q);
    a = (int*)malloc(sizeof(int)*Q);
    b = (int*)malloc(sizeof(int)*Q);
    for (size_t i = 0; i < N; i++) {
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
    for (size_t i = 0; i < x; i++) {
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
