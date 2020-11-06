#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
    // 定数
    double k = 1.4, delta = 1.0, X, M1 = 1.5, lambda, theta = M_PI*5/180;
    // 定数の計算
    double tan_beta, beta;
    // 近似計算
    lambda = sqrt( (pow((M1*M1-1), 2) - 3*(1+((k-1)/2)*M1*M1)*(1+((k+1)/2)*M1*M1)*pow(tan(theta), 2)) );
    X = (pow(M1*M1-1, 3) - 9*(1+((k-1)/2)*M1*M1)*(1+((k-1)/2)*M1*M1+((k+1)/4)*pow(M1, 4))*pow(tan(theta), 2))/pow(lambda, 3);
    tan_beta = (M1*M1-1 + 2*lambda*cos((4*M_PI*delta+acos(X))/3))/(3*(1+((k-1)/2)*M1*M1)*tan(theta));
    beta = atan(tan_beta);
    // 計算
    double M2, right;
    right = (1+((k-1)/2)*M1*M1*pow(sin(beta), 2))/(k*M1*M1*pow(sin(beta), 2) - (k-1)/2);
    M2 = right/(pow(sin(beta - theta), 2));
    M2 = sqrt(M2);
    // 出力
    printf("M_2U = %lf\n", M2);
    // 圧力の計算
    // 定数
    double P1 = 100, P2;
    // P_2Lの計算
    P2 = P1*M1*M1*pow(sin(beta), 2)*(2*k/(k+1)) - (k-1)/(k+1);
    // 出力
    printf("P_2L = %lf\n", P2 );
    return 0;
}
