#include <stdio.h>
#include <stdlib.h>
#define sizeN 101
int Ax, Ay, Bx, By; // 線分の始点と終点
int N; // 多角形の頂点数
// 位置ベクトル
typedef struct vec {
    int vecx, vecy;
} vec_t;
// 外積の計算
int crossProduct(vec_t a, vec_t b) {
    int product;
    product = a.vecx*b.vecy - b.vecx*a.vecy;
    return product;
}
// 線分が交差しているか判定
int isCross (vec_t start, vec_t end, vec_t p[]) {
    int cross = 0;  // 交差数
    double S1, S2;
    // ベクトル
    vec_t base, vec1, vec2;
    base.vecx = Bx-Ax; base.vecy = By-Ay;
    // 交差の判定
    for (size_t i = 0; i < N; i++) {
        vec1.vecx = p[i].vecx-Ax;
        vec1.vecy = p[i].vecy - Ay;
        vec2.vecx = p[(i+1)%N].vecx-Ax;
        vec2.vecy = p[(i+1)%N].vecy - Ay;
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
    vec_t start, end; // 始点 終点
    vec_t *point;
    // 入力
    scanf("%d %d %d %d", &start.vecx, &start.vecy, &end.vecx, &end.vecy);
    scanf("%d", &N);
    point = (vec_t *)malloc(sizeof(vec_t)*N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &point[i].vecx, &point[i].vecy);
    }
    // 出力
    isCross(start, end, point);
    free(point);
    return 0;
}
