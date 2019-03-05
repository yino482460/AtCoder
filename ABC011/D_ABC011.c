#include <stdio.h>
#include <string.h>
// 確率版コンビネーションを計算
double Combi (int n, int r) {
    double combi[n+1][n+1];
    memset(combi, 0, sizeof(combi));
    // 初期設定
    combi[0][0] = 1;
    // 組み合わせの計算
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j-1 >= 0) {
                combi[i][j] = (combi[i-1][j-1]+combi[i-1][j])*0.5;
            } else {
                combi[i][j] = combi[i-1][j]*0.5;
            }
        }
    }
    double ans = combi[n][r];
    for (size_t i = 0; i <= n; i++) {
        for (size_t j = 0; j <= n; j++) {
            printf("%lf ", combi[i][j] );
        }
        printf("\n");
    }
    return ans;
}

// 各場合の確率
double getNumOfCombination (int N, int nx, int ny, int horizon) {
    long vertical = N-horizon;
    if ((horizon+nx)%2 != 0) { return 0; }
    if ((vertical+ny)%2 != 0) { return 0; }
    long right = (horizon+nx)/2;
    long up = (vertical+ny)/2;
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
        probability = 0;
        return probability;
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
