#include <stdio.h>
#define max(a, b) (a>b ? a:b)

int main(int argc, char const *argv[]) {
    // 変数
    int N;
    // 入力
    scanf("%d", &N);
    // 質問 点 1から最も遠い頂点を探索
    int dist, maxdist = 0;
    int v;
    for (int i = 2; i <= N; i++) {
        printf("? 1 %d\n", i);
        fflush(stdout);
        scanf("%d", &dist);
        if (maxdist < dist) {
            maxdist = dist;
            v = i;
        }
    }
    // 木の直径を計算
    int ans = maxdist;
    for (int i = 1; i <= N; i++) {
        if (i == v) {
            continue;
        }
        printf("? %d %d\n", v, i);
        fflush(stdout);
        scanf("%d", &dist);
        if (ans < dist) {
            ans = dist;
        }
    }
    // 出力
    printf("! %d\n",ans);
    fflush(stdout);
    return 0;
}
