#include <stdio.h>
#include <math.h>
#define phi 5.0
#define M1 1.5
#define P1 100
#define k 1.4

int main(int argc, char const *argv[]) {
    /***** 問1 *****/
    // 定数
    double ap, am;
    ap = sqrt((k+1)/(k-1));
    am = sqrt((k-1)/(k+1));
    // 変数
    double v1, v, m, F, dF, diff;
    // M_2U
    double M_2U;
    // 初期値
    m = 1.0;
    v1 = ap*atan( am*sqrt(M1*M1-1) ) - atan( sqrt(M1*M1-1) );
    v = v1 + M_PI*phi/180;
    F = ap*atan(am*m) - atan(m) - v;
    dF = (ap*am)/(1+pow(am*m, 2)) - 1/(1+m*m);
    diff = fabs(F);
    // ニュートンラプソン法
    while ( diff > 0.0001) {
        m = m - F/dF;
        F = ap*atan(am*m) - atan(m) - v;
        dF = (ap*am)/(1+pow(am*m, 2)) - 1/(1+m*m);
        diff = fabs(F);
    }
    // 出力
    M_2U = sqrt(m*m+1);
    printf("M_2U = %lf\n", M_2U );
    // 圧力の計算
    // 変数
    double P0, P_2U;
    // 計算
    P0 = P1*pow(1+M1*M1*(k-1)/2, k/(k-1));
    P_2U = P0*pow(1+M_2U*M_2U*(k-1)/2, -k/(k-1));
    // 出力
    printf("P_2U = %lf kPa\n", P_2U);

    /***** 問2 *****/
    // 定数
    double delta = 1.0, X, lambda, theta = M_PI*phi/180;
    // 定数の計算
    double tan_beta, beta;
    // 近似計算
    lambda = sqrt( (pow((M1*M1-1), 2) - 3*(1+((k-1)/2)*M1*M1)*(1+((k+1)/2)*M1*M1)*pow(tan(theta), 2)) );
    X = (pow(M1*M1-1, 3) - 9*(1+((k-1)/2)*M1*M1)*(1+((k-1)/2)*M1*M1+((k+1)/4)*pow(M1, 4))*pow(tan(theta), 2))/pow(lambda, 3);
    tan_beta = (M1*M1-1 + 2*lambda*cos((4*M_PI*delta+acos(X))/3))/(3*(1+((k-1)/2)*M1*M1)*tan(theta));
    beta = atan(tan_beta);
    // 計算
    double M_2L, right;
    right = (1+((k-1)/2)*M1*M1*pow(sin(beta), 2))/(k*M1*M1*pow(sin(beta), 2) - (k-1)/2);
    M_2L = right/(pow(sin(beta - theta), 2));
    M_2L = sqrt(M_2L);
    // 出力
    printf("M_2U = %lf\n", M_2L);
    // 圧力の計算
    // 定数
    double P_2L;
    // P_2Lの計算
    P_2L = pow(M1*sin(beta), 2)*(2*k/(k+1)) - (k-1)/(k+1);
    P_2L = P1*P_2L;
    // 出力
    printf("P_2L = %lf kPa\n", P_2L );

    /***** 問3 *****/
    // 変数
    double L, D, l = 1.0;
    // 計算
    L = (P_2L - P_2U)*l*cos(theta);
    D = (P_2L - P_2U)*l*sin(theta);
    // 出力
    printf("L = %lf, D = %lf, L/D = %lf\n", L, D, 1/tan(theta));
    return 0;
}
