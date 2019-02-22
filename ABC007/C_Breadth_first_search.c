#include <stdio.h>
#define SIZE 52
#define Wall 100
int Board[SIZE][SIZE];

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

int main(int argc, char const *argv[]) {
    // 変数
    int R, C;
    int sy, sx, gy, gx;
    // 入力
    scanf("%d%d", &R, &C );
    scanf("%d%d%d%d", &sy, &sx, &gy, &gx);
    // 文字列を数字に変換
    trans_to_num(R, C);
    // 出力


    return 0;
}
