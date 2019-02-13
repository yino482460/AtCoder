#include <stdio.h>
#define N_max 12
#define M_max N_max*(N_max-1)/2
// 人間関係を収める配列
int relation[N_max][N_max] = {0};
// 人間関係を数値化する関数
void makeRelation (int M, int x[], int y[]) {
    for (size_t i = 0; i < M; i++) {
        relation[x[i]-1][y[i]-1] = 1;
        relation[y[i]-1][x[i]-1] = relation[x[i]-1][y[i]-1];
    }
}


int main(int argc, char const *argv[]) {
    // 変数
    int N, M;
    int x[M_max], y[M_max];
    // 入力
    scanf("%d%d", &N, &M );
    for (size_t i = 0; i < M; i++) {
        scanf("%d%d", &x[i], &y[i] );
    }
    // 人間関係を数値化
    makeRelation(M, x, y);

    return 0;
}
