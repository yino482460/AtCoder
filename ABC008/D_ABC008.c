#include <stdio.h>
#define gold 1
#define Machine -1

int main(int argc, char const *argv[]) {
    // 変数
    int W, H, N;
    scanf("%d %d %d", &W, &H, &N );
    int machine[N+1][2];    // 回収装置の座標
    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 0; j <= 1; j++) {
            scanf("%d", &machine[i][j] );
        }
    }

    return 0;
}
