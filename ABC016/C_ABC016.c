#include <stdio.h>
#define sizeN 11
int Friend[sizeN][sizeN];
// ワーシャルフロイド法
void WFmethod (int N) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            for (size_t k = 0; k < N; k++) {
                if (i == j) {
                    Friend[i][j] = 0;
                } else {
                    Friend[i][j] = Friend[i][k]+Friend[k][j];
                }
            }
        }
    }
    // 確認
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            printf("%2d ", Friend[i][j]);
        }
        printf("\n");
    }
    // 出力
    for (size_t i = 0; i < N; i++) {
        int cnt = 0;
        for (size_t j = 0; j < N; j++) {
            if (Friend[i][j] == 2) {
                cnt ++;
            }
        }
        printf("%d\n", cnt);
    }
}

int main(int argc, char const *argv[]) {
    // 変数
    int N, M;
    // 入力
    scanf("%d %d", &N, &M);
    int a, b;
    for (size_t i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        // 友達関係を構築する
        Friend[a][b] = 1;
        Friend[b][a] = Friend[a][b];
    }
    // ワーシャルフロイド
    WFmethod(N);
    return 0;
}
