#include <stdio.h>
#include <math.h>
#define phi 5.0

int main(int argc, char const *argv[]) {
    // 変数
    double L, D, theta = M_PI*phi/180, l = 1.0;
    // 計算
    double P_2L = 144.29, P_2U = 245.8;
    L = (P_2L - P_2U)*l*cos(theta);
    D = (P_2L - P_2U)*l*sin(theta);
    // 出力
    printf("L = %lf, D = %lf, L/D = %lf\n", L, D, 1/tan(theta));
    return 0;
}
