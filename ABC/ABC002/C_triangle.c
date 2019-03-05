#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double CalcTriangle (int x[], int y[]) {
    double area;
    int vector[2][2];
    // 位置ベクトルの計算
    for (size_t i = 0; i < 2; i++) {
        vector[i][0] = x[i+1] - x[0];
        vector[i][1] = y[i+1] - y[0];
    }
    // 面積の計算
    area = vector[0][0]*vector[1][1] - vector[0][1]*vector[1][0];
    area = 0.5*fabs(area);
    return area;
}

int main(int argc, char const *argv[]) {
    //変数
    int x[3], y[3];
    double ans;
    //入力
    for (size_t i = 0; i < 3; i++) {
        scanf("%d", &x[i] );
        scanf("%d", &y[i] );
    }
    // 計算
    ans = CalcTriangle(x, y);
    //出力
    printf("%.1lf\n", ans );
    return 0;
}
