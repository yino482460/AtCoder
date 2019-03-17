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
typedef struct vec {
    int vecx;
    int vecy;
} vec_t;
// 線分が交差しているか判定
int isCross (point_t point[]) {
    int cross = 0;
    double S1, S2;
    // ベクトル
    vec_t Main, vec1, vec2;
    Main.vecx = Bx-Ax; Main.vecy = By-Ay;
    // 交差の判定
    for (size_t i = 0; i < N; i++) {
        vec1.vecx = point[i].x-Ax; vec1.vecy = point[i].y - Ay;
        vec2.vecx = point[(i+1)%N].x-Ax; vec2.vecy = point[(i+1)%N].y - Ay;
        S1 = 0.5*(Main.vecx*vec1.vecy-vec1.vecx*Main.vecy);
        S2 = 0.5*(Main.vecx*vec2.vecy-vec2.vecx*Main.vecy);
        if (S1*S2 < 0) {
            cross ++;
        }
    }
    // printf("cross %d\n", cross);
    int ans = cross/2 +1;
    printf("%d\n", ans);
    return 0;
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
    // 出力
    isCross(point);
    free(point);
    return 0;
}
