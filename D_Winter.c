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
long long mod_nCr (int n, int r, long Mod) {
    tPascal[0][0] = 1;
    // 初期設定
    for (size_t i = 1; i <= n; i++) { tPascal[i][0] = 1; tPascal[i][i] = 1; }
    // 組み合わせの計算
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= n; j++) {
            tPascal[i][j] = (tPascal[i-1][j-1] + tPascal[i-1][j])%Mod;
        }
    }
    return tPascal[n][r];
}
// BitCount
int BitCount(int bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

// 包除原理から解に適さないものを除外
long long Inclusion_exclusion_principle (int R, int C, int X, int Y, int D, int L) {
    long long all = 0;
    long long Mod = nPow(10, 9) + 7;
    int combiXY;
    // X x Yスペースの配置の仕方
    combiXY = calc_combi_XY(R, C, X, Y);
    all = mod_nCr(X*Y, D+L, Mod)*mod_nCr(D+L, D, Mod);
    // 包除原理の本体
    if (D+L != X*Y) {
        for (size_t i = 0; i < 16; i++) {   // i=0は全体集合
            int sX = X;
            int sY = Y;
            // bit演算で場合分け
            if ( ((i >> 0)&1) == 1) {sY--;}
            if ( ((i >> 1)&1) == 1) {sY--;}
            if ( ((i >> 2)&1) == 1) {sX--;}
            if ( ((i >> 3)&1) == 1) {sX--;}
            // sX x sYの領域を検証
            if (sX<0 || sY<0) {continue;}
            // 包除原理の計算
            if ( (BitCount(i))%2 == 1) {    // 奇数個の集合
                all -= (mod_nCr(sX*sY, D+L, Mod)*mod_nCr(D+L, D, Mod))%Mod;
            } else {    // 偶数個の集合
                all += (mod_nCr(sX*sY, D+L, Mod)*mod_nCr(D+L, D, Mod))%Mod;
            }
        }
        all = (all*combiXY)%Mod;
    // D+L = X*Yのとき
    } else {
        all = (all*combiXY)%Mod;
    }
    return all;
}

int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d %d", &R, &C );
    scanf("%d %d", &X, &Y );
    scanf("%d %d", &D, &L );
    // 計算
    long long ans = 0;
    ans = Inclusion_exclusion_principle(R, C, X, Y, D, L);
    // 出力
    printf("%lld\n", ans );
    return 0;
}
