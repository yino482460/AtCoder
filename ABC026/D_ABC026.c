#include <stdio.h>
#include <math.h>
// 変数
double A, B, C;
// 関数
double TakahashiBall (double t) {
    double ans;
    ans = A*t + B*sin(C*t*M_PI);
    return ans;
}
// 二分検索で解を求める
void binSearch (double A, double B, double C) {
    double low = 0, high = 1000;
    double mid;
    for (size_t i = 0; i < 10000; i++) {
        mid = (low+high)/2;
        if ( TakahashiBall (mid) > 100) {
            high = mid;
        } else {
            low = mid;
        }
    }
    printf("M_PI %.30lf\n", M_PI);
    printf("%lf\n", low);
}
// メイン
int main(int argc, char const *argv[]) {
    // 入力
    scanf("%lf %lf %lf", &A, &B, &C);
    // 二分検索
    binSearch(A, B, C);
    return 0;
}
