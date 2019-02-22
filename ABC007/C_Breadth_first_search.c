#include <stdio.h>
#define SIZE 52
#define Wall 10000
int Board[SIZE][SIZE];
int vx[4] = {0, 1, 0, -1};
int vy[4] = {1, 0, -1, 0};

// 盤面を数字に変換
void  trans_to_num (int R, int C) {
    for (size_t i = 1; i <= R; i++) {
        for (size_t j = 0; j <= C; j++) {
            if (getchar() == '#') {
                Board[i][j] = Wall;
            } else {
                Board[i][j] = 0;
            }
        }
    }
}
// 迷路を攻略
int maze_solve (int startx, int starty) {
    for (size_t i = 0; i < 4; i++) {
        int nx = startx + vx[i];
        int ny = starty + vy[i];
        if (Board[nx][ny]!=Wall || Board[nx][ny]==0) {
            Board[nx][ny] = Board[startx][starty] + 1;
            maze_solve (nx, ny);
        }
    }
    return -1;  // 行き止まり
}


int main(int argc, char const *argv[]) {
    // 変数
    int R, C;
    int sy, sx, gy, gx;
    // 入力
    scanf("%d%d", &R, &C );
    scanf("%d%d%d%d", &sy, &sx, &gy, &gx);
    // 文字列を数字に変換
    trans_to_num(R, C);
    // 迷路の計算
    maze_solve(sx, sy);
    // 出力
    printf("%d\n", Board[gx][gy] );


    return 0;
}
