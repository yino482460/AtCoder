#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max(a, b) (a>b ? a:b)
// 座標
typedef struct point {
    double x, y;
    double w;   // 質量
} point_t;
// 二点間の距離
double calcDistance (point_t a, point_t b) {
    double distance;
    double A, B;
    A = a.x-b.x; B = a.y-b.y;
    distance = sqrt(A*A+B*B);
    return distance;
}
// 多数の点の重心
point_t calcCenter (int N, point_t a[]) {
    point_t center;
    double weight = 0;
    for (size_t i = 0; i < N; i++) {
        weight += a[i].w;
        center.x += a[i].w*a[i].x;
        center.y += a[i].w*a[i].y;
    }
    center.x /= weight;
    center.y /= weight;
    return center;
}
// 点の初期化
void  InitWeight (int N, point_t a[]) {
    for (size_t i = 0; i < N; i++) {
        a[i].w = 1;
    }
}
// 膨張速度の計算
void calcExpansionRate (int N, point_t A[], point_t B[]) {
    point_t CenterA, CenterB;
    InitWeight(N, A); InitWeight(N, B);
    CenterA = calcCenter(N, A);
    CenterB = calcCenter(N, B);
    // 重心から最も離れた点までの距離
    double maxDisA = 0, maxDisB = 0;
    for (size_t i = 0; i < N; i++) {
        maxDisA = max(maxDisA, calcDistance(CenterA, A[i]));
        maxDisB = max(maxDisB, calcDistance(CenterB, B[i]));
    }
    // 膨張速度
    double ExpansionRate;
    ExpansionRate = maxDisB/maxDisA;
    // 出力
    printf("ans %.10lf\n", ExpansionRate);
}

// メイン
int main(int argc, char const *argv[]) {
    // 変数
    int N;
    scanf("%d", &N);
    point_t A[N], B[N];
    // 入力
    for (size_t i = 0; i < N; i++) {
        scanf("%lf %lf", &A[i].x, &A[i].y);
    }
    for (size_t i = 0; i < N; i++) {
        scanf("%lf %lf", &B[i].x, &B[i].y);
    }
    // 出力
    calcExpansionRate(N, A, B);
    // メモリ解放
    // free(A); free(B);
    return 0;
}
