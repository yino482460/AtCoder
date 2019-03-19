#include <stdio.h>
#include <stdlib.h>
#define Rmax 500
#define sizeC 500
// 色の数字
enum {
    white,
    black,
    green,
};
// 盤面を構築
void structBord (int R, int C, char **s, int **board) {
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            if (s[i][j] == 'o') {   // 白いマス
                board[i][j] = white;
            } else if (s[i][j] == 'x') {
                board[i][j] = black;
            }
        }
    }

}

int main(int argc, char const *argv[]) {
    // 変数
    int R, C, K;
    char **s;
    int **board;
    // 入力
    scanf("%d %d %d", &R, &C, &K);
    // 文字列の領域を確保
    s = (char **)malloc(sizeof(char *)*R);
    board = (int **)malloc(sizeof(int *)*R);
    for (size_t i = 0; i < R; i++) {
        s[i] = (char *)malloc(sizeof(char)*(C+1));
        board[i] = (int *)malloc(sizeof(int)*C);
        scanf("%s", s[i]);  // 文字列を取得
    }

    // メモリ解放
    for (size_t i = 0; i < R; i++) {
        free(s[i]);
        free(board[i]);
    }
    return 0;
}
