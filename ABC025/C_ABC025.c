#include <stdio.h>
#define max(a, b) (a>b ? a:b)
#define min(a, b) (a<b ? a:b)
// 変数
int Grid[3][3];
int b[2][3];
int c[3][2];
int score;
int total = 0;
const int INF = 100000;
// マスの初期化
void InitGrid ( ) {
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            Grid[i][j] = -1;    // 未探索
        }
    }
}
// 得点の計算
int calcScore () {
    int ret = 0;
   for (int i = 0; i < 2; i++) {
       for (int j = 0; j < 3; j++) {
           if (Grid[i][j] == Grid[i+1][j]) {
               ret += b[i][j];
           }
       }
   }
   for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 2; j++) {
           if (Grid[i][j] == Grid[i][j+1]) {
               ret += c[i][j];
           }
       }
   }
   return ret - (total-ret);
}
// 深さ優先探索
int Dfs (int turn) {
    if (turn == 9) {
        return calcScore ();
    }
    int ret = (turn%2 == 0) ? -INF:INF;
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (Grid[i][j] == -1) {
                Grid[i][j] = (turn%2 == 0) ? 1:0;
                ret = (turn%2 == 0) ? max(ret, Dfs(turn+1)) : min(ret, Dfs(turn+1));
                Grid[i][j] = -1;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    // 入力
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 3; j++) {
            scanf("%d", &b[i][j]);
            total += b[i][j];
        }
    }
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 2; j++) {
            scanf("%d", &c[i][j]);
            total += c[i][j];
        }
    }
    InitGrid();
    int ans = (Dfs(0)+total) / 2;
    printf("%d\n", ans);
    printf("%d\n", total - ans);
    return 0;
}
