#include <stdio.h>
#include <stdlib.h>
#define sizeN 101
int Ax, Ay, Bx, By; // 線分の始点と終点
int N; // 多角形の頂点数
// 座標
typedef struct point {
    int x;
    int y;
} point_t;
// 線分が交差しているか判定
int isCross (point_t point[]) {
    int cross = 0;

    return cross;
}

int main(int argc, char const *argv[]) {
    // 変数
    point_t *point;
    // 入力
    scanf("%d %d %d %d", &Ax, &Ay, &Bx, &By);
    scanf("%d", &N);
    point = (point_t *)malloc(sizeof(point_t)*N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &point[i].x, &point[i].y);
    }

    free(point);
    return 0;
}
