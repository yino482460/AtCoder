#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 52
#define Wall -100
#define Aisle -1
// キューの構造体
typedef struct Queue {
    int x, y;
} Queue;
// キューの作成
Queue que[SIZE*SIZE];
// 盤面の状態
int Board[SIZE][SIZE];
int vx[4] = {0, 1, 0, -1};
int vy[4] = {1, 0, -1, 0};
// 変数
int R, C;
int sy, sx, gy, gx;

// 盤面を数字に変換
void  trans_to_num (int R, int C) {
    for (size_t i = 1; i <= R; i++) {
        for (size_t j = 0; j <= C; j++) {
            if (getchar() == '#') {
                Board[i][j] = Wall;
            } else {
                Board[i][j] = Aisle;
            }
        }
    }
}
// 迷路を攻略
void solve_maze (int startx, int starty, int goalx, int goaly) {
    // que[0]はスタート位置
    que[0].x = startx; que[0].y = starty;
    Board[starty][startx] = 0;
    // キューを見ている位置
    int head = 0, tail = 1;
    // 探索
    while (head != tail) {
        int x, y;
        x = que[head].x;
        y = que[head].y;
        head = head + 1;
        for (size_t i = 0; i < 4; i++) {
            int nx = x + vx[i];
            int ny = y + vy[i];
            if ((nx>1 && nx<=C) && (ny>1 && ny<=R) && Board[ny][nx]==Aisle && Board[ny][nx]!=Wall) {
                Board[ny][nx] = Board[y][x] + 1;
                que[tail].x = nx;
                que[tail].y = ny;
                tail = tail + 1;
            }
        }

    }
    printf("%d\n", Board[goaly][goalx] );
}


int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d%d", &R, &C );
    scanf("%d%d%d%d", &sy, &sx, &gy, &gx);
    // 文字列を数字に変換
    trans_to_num(R, C);
    // 迷路の計算
    solve_maze(sx, sy, gx, gy);
    return 0;
}
