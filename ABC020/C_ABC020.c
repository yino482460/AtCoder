#include <stdio.h>
#include <stdlib.h>
int H, W, T;
int sx, sy, gx, gy;
// 色の数字
enum {
    white,
    black,
};
typedef struct point {
    long x, y;
} point_t;
// 二分累乗
long lPow(int n, int m) {
    if (m == 0) {
        return n;
    } else if (m%2 == 2) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return n*lPow(n, m-1);
    }
}
// 文字を数字に変換
void setStartGoal (char **s, point_t **maze) {
    for (size_t i = 0; i < H; i++) {
        for (size_t j = 0; j < W; j++) {
            if (s[i][j] == 'S') {
                sx = j, sy = i;
                s[i][j] = '.';
            }
            if (s[i][j] == 'G') {
                gx = j, gy = i;
                s[i][j] = '.';
            }
        }
    }
}
// ダイストラクタ法

int main(int argc, char const *argv[]) {
    // 変数
    char **s;
    point_t **maze;
    // 入力
    scanf("%d %d %d", &H, &W, &T);
    // メモリ確保
    s = (char **)malloc(sizeof(char *)*H);
    maze = (point_t **)malloc(sizeof(point_t *)*H);
    for (size_t i = 0; i < H; i++) {
        s[i] = (char *)malloc(sizeof(char)*(W+1));
        maze[i] = (point_t *)malloc(sizeof(point_t)*W);
    }
    for (size_t i = 0; i < H; i++) {
        for (size_t j = 0; j < (W+1); j++) {
            scanf("%s", &s[i][j]);
        }
    }
    // 数字に変換
    setStartGoal(s, maze);



    // メモリ解放
    free(s); free(maze);
    for (size_t i = 0; i < H; i++) {
        free(s[i]); free(maze[i]);
    }

    return 0;
}
