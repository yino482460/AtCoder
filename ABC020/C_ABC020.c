#include <stdio.h>
#include <stdlib.h>
int H, W, T;
// 色の数字
enum {
    white,
    black,
};
typedef struct point {
    int x, y;
} point_t;
// 文字を数字に変換
void MazeToDigit(char **s, point_t **maze) {
    for (size_t i = 0; i < H; i++) {
        for (size_t j = 0; j < W; j++) {
            if (s[i][j] == 'S' || s[i][j] == 'G') {
                maze[i][j].x = j;
                maze[i][j].y = i;
            } else if (s[i][j] == '.') {
                maze[i][j].x = white;
                maze[i][j].y = white;
            } else {
                maze[i][j].x = black;
                maze[i][j].y = black;
            }
        }
    }
}

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
    MazeToDigit(s, maze);



    // メモリ解放
    free(s); free(maze);
    for (size_t i = 0; i < H; i++) {
        free(s[i]); free(maze[i]);
    }

    return 0;
}
