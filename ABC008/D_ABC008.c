#include <stdio.h>
#define gold 1
#define machine -1
#define Max 1000001
#define max(a, b) (a>b ? a:b)
int Board[Max][Max];
// 金塊と装置を盤面に配置
void setGolds (int W, int H, int N, int location[][2]) {
    // 金塊の配置
    for (size_t i = 1; i <= H; i++) {
        for (size_t j = 1; j <= W; j++) {
            Board[i][j] = gold;
        }
    }
    // クレーンを配置
    for (size_t i = 0; i < N; i++) {
        int x = location[i][0];
        int y = location[i][1];
        Board[y][x] = machine;
    }
}

// 金塊の回収
int solve (int x, int y) {
    int ans = 0;
    while (Board[y+1][x] !=0) {
        Board[y+1][x] = 0;
        y++;
        ans++;
    }


    return ans;
}

int main(int argc, char const *argv[]) {
    // 変数
    int W, H, N;
    scanf("%d %d %d", &W, &H, &N );
    int location[N+1][2];    // 回収装置の座標
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j <= 1; j++) {
            scanf("%d", &location[i][j] );
        }
    }
    // 盤面の設定
    setGolds(W, H, N, location);
    // 金塊の回収
    solve(location[1][0], location[1][1]);
    // 確認
    for (size_t i = 0; i <= H; i++) {
        for (size_t j = 0; j <= W; j++) {
            printf("%2d", Board[i][j] );
        }
        printf("\n");
    }
    return 0;
}
