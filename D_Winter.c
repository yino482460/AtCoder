#include <stdio.h>
#include <math.h>
#define R_max 30
#define C_max 30
#define P_max R_max*R_max
long long tPascal[P_max+1][P_max+1] ;
// 変数
int R, C, X, Y, D, L;
// 机とサーバーラックの配置の組み合わせ
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
void mod_calc_nCr (int n, int r, long Mod) {
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

// 包除原理から解に適さないものを除外
long long Inclusion_exclusion_principle (int X, int Y, int D, int L) {
    long long all = 0;
    long long Mod = nPow(10, 9) + 7;
    // X x Yスペースの配置の仕方
    all = calc_combi_XY(R, C, X, Y); // これは最後にかけた方が良い?
    // 机とサーバーラックの組み合わせの余りを計算
    int area = X*Y;
    mod_calc_nCr(area, D, Mod);
    mod_calc_nCr(area-D, L, Mod);
    all *= (tPascal[area][D]*tPascal[area-D][L]);

    if (D+L != X*Y) {   // 包除原理の本体
        for (size_t i = 0; i <= 1; i++) {
            for (size_t j = 0; j <= 1; j++) {
                area = (X-i)*(Y-j);
                mod_calc_nCr(area, D, Mod);
                mod_calc_nCr(area-D, L, Mod);
            }
        }


    // D+L = X*Yのとき
    } else {
        all = all%Mod;
    }

    return all;
}

int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d %d", &R, &C );
    scanf("%d %d", &X, &Y );
    scanf("%d %d", &D, &L );

    long long ans = 0;
    // 出力
    printf("%lld\n", ans );
    return 0;
}
