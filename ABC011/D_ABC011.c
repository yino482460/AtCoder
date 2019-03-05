#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 確率版コンビネーションを計算
double Combi (long n, long r) {
    double combi[n+1][n+1];
    // 初期設定
    combi[0][0] = 1;
    // 組み合わせの計算
    for (long i = 1; i <= n; i++) {
        for (long j = 0; j <= i; j++) {
            if (j-1 >= 0) {
                combi[i][j] = (combi[i-1][j-1]+combi[i-1][j])*0.5;
            } else {
                combi[i][j] = combi[i-1][j]*0.5;
            }
        }
    }
    double ans = combi[n][r];
    return ans;
}

// 各場合の確率
double getNumOfCombination (int N, int nx, int ny, int horizon) {
    long vertical = N-horizon;
    if ((horizon-nx)%2 != 0) { return 0; }
    if ((vertical-ny)%2 != 0) { return 0; }
    long right = nx+(horizon-nx)/2;
    long up = ny+(vertical-ny)/2;
    if (right<0 || up<0) { return 0;}
    // 確率
    double p = 0;
    p = Combi(N, horizon)*Combi(horizon, right)*Combi(vertical, up);
    return p;
}

// 全確率の計算
double Jump (int N, int D, int X, int Y) {
    double probability = 0;
    if (X%D!=0 || Y%D!=0) {
        return 0;
    }
    int nx = X/D;
    int ny = Y/D;
    for (int horizon = 0; horizon <= N; horizon++) {
        probability += getNumOfCombination(N, nx, ny, horizon);
    }
    return probability;
}

int main(int argc, char const *argv[]) {
    // 変数
    int N, D;
    int X, Y;
    // 入力
    scanf("%d %d", &N, &D );
    scanf("%d %d", &X, &Y );
    // 出力
    double ans = Jump(N, D, X, Y);
    printf("%lf\n", ans);
    return 0;
}
