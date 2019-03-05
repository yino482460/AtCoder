#include <stdio.h>
#define size_M 44850
#define INF 10000
#deifine min(a, b) (a<b ? a:b)
// ワーシャルフロイド法
int WarshallFloyd (int N, int M, int a[], int b[], int t[]) {
    int minTime = INF;
    int distanse[M][M];

    return minTime;
}

int main(int argc, char const *argv[]) {
    // 変数
    int N, M;
    int a[size_M], b[size_M], t[size_M];
    // 入力
    scanf("%d %d", &N, &M);
    for (size_t i = 0; i < M; i++) {
        scanf("%d %d %d", &a[i], &b[i], &t[i]);
    }

    return 0;
}
