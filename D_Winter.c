#include <stdio.h>
#include <math.h>
#define R_max 30
#define C_max 30
#define P_max R_max*R_max
long long tPascal[P_max+1][P_max+1] ;

int calc_combi_XY ( int R, int C, int X, int Y ) {
    int combiXY = 0;
    combiXY = (R - X + 1)*(C - Y + 1);
    return combiXY;
}

// 繰り返し2乗法
long long nPow(int x, int y) {
    if (y == 0) {
        return 1;
    } else if (y == 1) {
        return x;
    } else if (y%2 == 0) {
        return nPow(x, y/2)*nPow(x, y/2);
    } else {
        return nPow(x, y/2)*nPow(x, y/2)*x;
    }
}

// Pascalの三角形と余りの性質を利用してnCrの余りを計算
void calc_nCr (int n, int r, long Mod) {
    tPascal[0][0] = 1;
    // 初期設定
    for (size_t i = 1; i <= n; i++) { tPascal[i][0] = 1; tPascal[i][i] = 1; }
    // 組み合わせの計算
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= n; j++) {
            tPascal[i][j] = tPascal[i-1][j-1]%Mod + tPascal[i-1][j]%Mod;
        }
    }
}

int main(int argc, char const *argv[]) {
    // 変数
    int R, C;
    int X, Y;
    int D, L;
    // 入力
    scanf("%d %d", &R, &C );
    scanf("%d %d", &X, &Y );
    scanf("%d %d", &D, &L );
    // X x Yスペースの配置の仕方
    long long ans;
    long Mod = nPow(10, 9) + 7;
    int combiXY = calc_combi_XY(R, C, X, Y);
    // 机とサーバーラックの組み合わせを計算
    calc_nCr(X*Y, D, Mod); calc_nCr(X*Y-D, L, Mod);
    ans = combiXY*(tPascal[X*Y][D]*tPascal[X*Y-D][L]);
    ans = ans%Mod;
    // 出力
    printf("%lld\n", ans );
    return 0;
}
