#include <stdio.h>
#define gold 1
#define machine -1
#define Max 1000001
#define m_max 32
#define max(a, b) (a>b ? a:b)
int Board[Max][Max];
int vx[4] = {0, 0, 1, -1};
int vy[4] = {1, -1, 0, 0};
int DP[m_max][m_max][m_max][m_max];
// 金塊と装置を盤面に配置
void setGolds (int W, int H, int N, int X[], int Y[]) {
    // 金塊の配置
    for (size_t i = 1; i <= H; i++) {
        for (size_t j = 1; j <= W; j++) {
            Board[i][j] = gold;
        }
    }
    // クレーンを配置
    for (size_t i = 0; i < N; i++) {
        int x = X[i];
        int y = Y[i];
        Board[y][x] = machine;
    }
}
// 金塊の回収
int getGold (int x, int y) {
    int ans = 0;
    for (size_t i = 0; i < 4; i++) {
        int ny = y+vy[i];
        int nx = x+vx[i];
        while (Board[ny][nx] != 0) {
            Board[ny][nx] = 0;  // 金塊を回収
            ans ++;
            if (nx > x) { nx++; }
            if (nx < x) { nx--; }
            if (ny > y) { ny++; }
            if (ny < y) { ny--; }
        }
    }
    return ans;
}

// 総当たり
/*
int Solve (int lx, int ly, int rx, int ry) {
    if (DP[lx][ly][rx][ry] != 0) { return DP[lx][ly][rx][ry];}


}
*/


int main(int argc, char const *argv[]) {
    // 変数
    int W, H, N;
    scanf("%d %d %d", &W, &H, &N );
    int X[N], Y[N];    // 回収装置の座標
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &X[i], &Y[i] );
    }
    // 盤面の設定
    setGolds(W, H, N, X, Y);
    // 金塊の回収
    int ans = getGold(X[1], Y[1]);
    // 確認
    for (size_t i = 1; i <= H; i++) {
        for (size_t j = 1; j <= W; j++) {
            printf("%2d", Board[i][j] );
        }
        printf("\n");
    }
    printf("ans %d\n", ans );
    return 0;
}
