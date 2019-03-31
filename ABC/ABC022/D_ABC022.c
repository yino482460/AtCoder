#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max(a, b) (a>b ? a:b)
// 座標
typedef struct point {
    double x, y;
} point_t;
// 重心
typedef struct center {
    double xg, yg;  // 重心の座標
    double Area;    // 三角形の面積
} center_t;
// 二点間の距離
double calcDistance (point_t a, point_t b) {
    double distance;
    double A, B;
    A = a.x-b.x; B = a.y-b.y;
    distance = sqrt(A*A+B*B);
    return distance;
}
// 三角形の重心
center_t TriangleCenter (point_t a, point_t b) {
    center_t area;
    area.xg = (a.x+b.x)/3;
    area.yg = (a.y+b.y)/3;
    area.Area = fabs( (a.x*b.y - a.y*b.x) )/2;
    return area;
}
// 多数の点の重心を計算
point_t pointsCenter (int N, point_t P[]) {
    point_t Center;
    double gX = 0, gY = 0;
    double sumArea = 0;
    // 多角形の面積がら重心を計算
    center_t p;
    for (size_t i = 0; i < N; i++) {
        p = TriangleCenter(P[i], P[(i+1)%N]);
        gX = p.xg*p.Area;
        gY = p.yg*p.Area;
        sumArea += p.Area;
    }
    // 重心
    Center.x = gX/sumArea;
    Center.y = gY/sumArea;
    return Center;
}
// 重心から最も離れた点までの距離を計算
double calcFarPointDistance (int N, point_t Center, point_t P[]) {
    double maxdist = 0;
    point_t p;
    p.x = Center.x; p.y = Center.y;
    // 計算
    for (size_t i = 0; i < N; i++) {
        maxdist = max(maxdist, calcDistance(p, P[i]));
    }
    return maxdist;
}
// 膨張速度の計算
void calcExpansionRate (int N, point_t A[], point_t B[]) {
    point_t cA, cB;
    cA = pointsCenter(N, A);
    cB = pointsCenter(N, B);
    // 重心から最も離れた点までの距離
    double disA, disB;
    disA = calcFarPointDistance(N, cA, A);
    disB = calcFarPointDistance(N, cB, B);
    // 膨張速度
    double ExpansionRate;
    ExpansionRate = disB/disA;
    // 出力
    printf("ans %lf\n", ExpansionRate);
}

// メイン
int main(int argc, char const *argv[]) {
    // 変数
    int N;
    scanf("%d", &N);
    point_t A[N], B[N];
    // 入力
    //A = (point_t *)malloc(sizeof(point_t)*N);
    //B = (point_t *)malloc(sizeof(point_t)*N);
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
