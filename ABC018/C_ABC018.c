#include <stdio.h>
#include <stdlib.h>
#define Rmax 500
#define sizeC 500
// 色に数字を割り当て
enum {
    black,
    white,
    green,
};
// 変数
int R, C, K;
char **s;
int **board;
// 盤面を構築
void structBord (char **s, int **board) {
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            if (s[i][j] == 'o') {   // 白いマス
                board[i][j] = white;
            } else if (s[i][j] == 'x') {    // 黒いマス
                board[i][j] = black;
            }
        }
    }
}
// 縦方向の累積和を計算
void  calcBoardSum (int **board) {
    for (size_t i = 1; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            if (board[i][j] != black) {
                board[i][j] += board[i-1][j];
            }
        }
    }
}
// 点 i,j が一辺 Kの中心になり得るかを判定
int check (int x, int y) {
    if (board[y][x] >= K) {
        for (int i = -K; i <= K; i++) {
            int dif = K - abs(i);   // 縦方向に下がる距離
            int nx, ny;
            nx = x+i; ny = y+dif;
            if (nx<0 || nx>=C || ny<0 || ny>=R) {
                return 0;   // 菱形を作れない
            }
            int boader = dif*2+1;
            if (board[ny][nx] < boader) {
                return 0;   // 菱形を作れない
            }
        }
    } else {
        return 0;   // 菱形を作れない
    }
    return 1;   // 菱形を作れる
}
// 菱形の数を計算する
void countDiamonds (int R, int C, int K, int **board) {
    structBord(s, board);
    calcBoardSum(board);
    int cnt = 0;
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            cnt += check(j, i);
        }
    }
    printf("%d\n", cnt);
}

int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d %d %d", &R, &C, &K);
    K--;    // Kのデクリメント
    // 文字列の領域を確保
    s = (char **)malloc(sizeof(char *)*R);
    board = (int **)malloc(sizeof(int *)*R);
    for (size_t i = 0; i < R; i++) {
        s[i] = (char *)malloc(sizeof(char)*(C+1));
        board[i] = (int *)malloc(sizeof(int)*C);
        scanf("%s", s[i]);  // 文字列を取得
    }
    // 出力
    countDiamonds(R, C, K, board);
    // メモリ解放
    for (size_t i = 0; i < R; i++) {
        free(s[i]);
        free(board[i]);
    }
    return 0;
}
