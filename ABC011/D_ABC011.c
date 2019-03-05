#include <stdio.h>
#include <string.h>
// 確率版コンビネーションを計算
double Combi (long n, long r) {
    double combi[n+1][n+1];
    memset(combi, 0, sizeof(combi));
    // 初期設定
    combi[0][0] = 1;
    // 組み合わせの計算
    for (long i = 1; i <= n; i++) {
        for (long j = 0; j <= i; j++) {
            if (j-1 >= 0) {
                combi[i][j] = (combi[i-1][j-1]+combi[i-1][j])/2;
            } else {
                combi[i][j] = combi[i-1][j]/2;
            }
        }
    }
    double ans = combi[n][r];
    printf("n %ld, r %ld, ans %lf\n", n, r, ans );
    return ans;
}

// 各場合の確率
double getNumOfCombination (long N, long nx, long ny, long horizon) {
    long vertical = N-horizon;
    if ((horizon+nx)%2 != 0) { return 0; }
    if ((vertical+ny)%2 != 0) { return 0; }
    long right = (horizon+nx)/2;
    long up = (vertical+ny)/2;
    if (right<0 || up<0) { return 0;}
    // 確率
    double p = 0;
    p = Combi(N, horizon)*Combi(horizon, right)*Combi(vertical, up);
    printf("p %lf\n", p );
    return p;
}

// 全確率の計算
double Jump (long N, long D, long X, long Y) {
    double probability = 0;
    if (X%D!=0 || Y%D!=0) {
        probability = 0;
        return probability;
    }
    long nx = X/D;
    long ny = Y/D;
    for (long horizon = 0; horizon <= N; horizon++) {
        probability += getNumOfCombination(N, nx, ny, horizon);
        printf("probability %lf\n", probability );
    }
    return probability;
}

int main(int argc, char const *argv[]) {
    // 変数
    long N, D;
    long X, Y;
    // 入力
    scanf("%ld %ld", &N, &D );
    scanf("%ld %ld", &X, &Y );
    // 出力
    double ans = Jump(N, D, X, Y);
    printf("%.15lf\n", ans);
    return 0;
}
