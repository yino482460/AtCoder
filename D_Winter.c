#include <stdio.h>
#define R_max 30
#define C_max 30
long tPascal[R_max+1][R_max+1] ;

int calc_combi_XY ( int R, int C, int X, int Y ) {
    int combiXY = 0;
    combiXY = (R - X + 1)*(C - Y + 1);
    return combiXY;
}

// Pascalの三角形を利用してnCrを計算
void calc_nCr (int n, int r) {
    tPascal[0][0] = 1;
    // 初期設定
    for (size_t i = 1; i <= n; i++) { tPascal[i][0] = 1; tPascal[i][i] = 1; }
    // 組み合わせの計算
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= n; j++) {
            tPascal[i][j] = tPascal[i-1][j-1] + tPascal[i-1][j];
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
    long ans;
    int combiXY = calc_combi_XY(R, C, X, Y);
    printf("combiXY %d\n", combiXY );
    // 机とサーバーラックの組み合わせを計算
    calc_nCr(X*Y, L);
    ans = combiXY*tPascal[X*Y][D];
    // 出力
    printf("%ld\n", ans );
    return 0;
}
