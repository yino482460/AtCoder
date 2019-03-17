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
int isCross (point_t p[]) {
    int cross = 0;  // 交差数
    double S1, S2;
    // ベクトル
    vec_t base, vec1, vec2;
    base.vecx = Bx-Ax; base.vecy = By-Ay;
    // 交差の判定
    for (size_t i = 0; i < N; i++) {
        vec1.vecx = p[i].x-Ax;
        vec1.vecy = p[i].y - Ay;
        vec2.vecx = p[(i+1)%N].x-Ax;
        vec2.vecy = p[(i+1)%N].y - Ay;
        S1 = 0.5*(base.vecx*vec1.vecy-vec1.vecx*base.vecy);
        S2 = 0.5*(base.vecx*vec2.vecy-vec2.vecx*base.vecy);
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
    point = (point_t *)malloc(sizeof(point_t)*(N+1));
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &point[i].x, &point[i].y);
    }
    // 出力
    isCross(point);
    free(point);
    return 0;
}
