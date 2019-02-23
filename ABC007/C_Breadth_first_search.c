#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 52
#define Wall -10
// 迷路
typedef struct Cell {
    int x, y;
    int step;
} Cell;
// キュー
typedef struct Queue {
    int front, rear, count, size;
    Cell *cell;
} Queue;
// キューの作成
Queue *make_queue (int n) {
    Queue *que = malloc(sizeof(Queue));
    if (que != NULL) {
    que->front = 0;    que->rear = 0;
    que->count = 0;    que->size = n;
    que->cell = malloc(sizeof(Cell) * n);
    if (que->cell == NULL) {
      free(que);
      return NULL;
    }
  }
  return que;
}
// キューは満杯か
bool is_full(Queue *que){
  return que->count == que->size;
}
// データの挿入
bool enqueue(Queue *que, Cell grid) {
    if (is_full(que)) return false;
    que->cell[que->rear++] = grid;
    que->count++;
    if (que->rear == que->size)
        que->rear = 0;
    return true;
}
// キューは空か
bool is_empty(Queue *que) {
  return que->count == 0;
}

// データを取り出す
double dequeue(Queue *que, bool *err){
  if (is_empty(que)) {
    *err = false;
    return 0;
  }
  Cell grid = que->cell[que->front++];
  que->count--;
  *err = true;
  if (que->front == que->size)
    que->front = 0;
  return grid;
}



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
