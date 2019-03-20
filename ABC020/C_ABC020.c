#include <stdio.h>
#include <stdlib.h>
int H, W, T;
int sx, sy, gx, gy;
// 座標の情報
typedef struct que {
    long x, y;
} que_t;
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
void setBoard (char **s, long **dist) {
    // 各マスの距離を無前に設定
    long INF = lPow(10, 10);
    for (size_t i = 0; i < H; i++) {
        for (size_t j = 0; j < (W+1); j++) {
            scanf("%s", &s[i][j]);
            dist[i][j] = INF;
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
    //  スタート地点は0
    dist[sy][sx] = 0;
}
// ダイストラクタ法
long Dijkstra (int cost, long **dist) {
    

    return dist[gy][gx];
}


int main(int argc, char const *argv[]) {
    // 変数
    char **s;
    long **dist;    // 各マス目までの距離
    // 入力
    scanf("%d %d %d", &H, &W, &T);
    // メモリ確保
    s = (char **)malloc(sizeof(char *)*H);
    dist = (long **)malloc(sizeof(long *)*H);
    for (size_t i = 0; i < H; i++) {
        s[i] = (char *)malloc(sizeof(char)*(W+1));
        dist[i] = (long *)malloc(sizeof(long)*W);
    }
    // 盤面の入力とスタートとゴールの座標の取得
    setBoard(s, dist);
    // ダイストラクタ法



    // メモリ解放
    free(s); free(dist);
    for (size_t i = 0; i < H; i++) {
        free(s[i]); free(dist[i]);
    }
    return 0;
}
