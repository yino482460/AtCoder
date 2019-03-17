#include <stdio.h>
#define sizeN 11
int Friend[sizeN][sizeN];

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

    return 0;
}
