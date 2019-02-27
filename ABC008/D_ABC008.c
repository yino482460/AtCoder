#include <stdio.h>
#define gold 1
#define Machine -1
#define Max 1000001
int Board[Max][Max];
// 金塊と装置を盤面に配置
void setGolds (int W, int H, int N, int machine[][2]) {
    // 金塊の配置
    for (size_t i = 1; i <= H; i++) {
        for (size_t j = 1; j <= W; j++) {
            Board[i][j] = gold;
        }
    }
    // クレーンを配置
    for (size_t i = 0; i < N; i++) {
        int x = machine[i][0];
        int y = H+1-machine[i][1];
        Board[y][x] = Machine;
    }

}

int main(int argc, char const *argv[]) {
    // 変数
    int W, H, N;
    scanf("%d %d %d", &W, &H, &N );
    int machine[N+1][2];    // 回収装置の座標
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j <= 1; j++) {
            scanf("%d", &machine[i][j] );
        }
    }
    // 盤面の設定
    setGolds(W, H, N, machine);
    // 確認
    for (size_t i = 0; i <= H; i++) {
        for (size_t j = 0; j <= W; j++) {
            printf("%2d", Board[i][j] );
        }
        printf("\n");
    }

    return 0;
}
