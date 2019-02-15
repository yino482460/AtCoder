#include <stdio.h>
#define N_max 12
#define M_max N_max*(N_max-1)/2
// 訪問フラグ
int visit[N_max+1] = {0};
// 人間関係を収める配列
int relation[N_max+1][N_max+1] = {0};
// 人間関係を数値化する関数
void makeRelation (int M, int x[], int y[]) {
    // わかりやすくするために0行, 0列を除く
    for (size_t i = 0; i < M; i++) {
        relation[x[i]][y[i]]  = 1;
        relation[y[i]][x[i]] = relation[x[i]][y[i]];
    }
}

// 深さ優先探索
int max_Factions = 1;
void DepthFirstSearch (int N, int start) {
    int Factions = max_Factions;
    int next;
    //停止条件を仕込んでいない
    for ( next = 1; next <= N ; next++) {
        if ( (relation[start][next] == 1) && (visit[start] == 0) ) {
            visit[start] = 1;   // 訪問フラグ
            Factions ++;
            DepthFirstSearch(N,  next);
            visit[start] = 0;   // 訪問フラグをリセット
        }
        if ( Factions > max_Factions ) {
            max_Factions = Factions;
        }
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

    // 人間関係を表示
    for (size_t i = 0; i <= N; i++) {
        for (size_t j = 0; j <= N; j++) {
            printf("%2d", relation[i][j] );
        }
        printf("\n");
    }

    // 最大派閥を計算
    /* for (size_t i = 1; i <= N; i++) {
        DepthFirstSearch(N, i);
    } */
    // 出力
    printf("%d\n", max_Factions );
    return 0;
}
