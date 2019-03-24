#include <stdio.h>
#include <stdlib.h>

// 二分累乗
long lPow (long n, long m) {
    if (m == 0) {
        return 1;
    } else if (m == 1) {
        return n;
    } else if (m%2 == 0) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return n*lPow(n, m-1);
    }
    printf("call lPow\n");
}
// 階乗の計算
void lFactrial (int n, long Mod, long *factrial) {
    if (n == 0) {
        factrial[0] = 1;
    }
    for (size_t i = 0; i <= n; i++) {
        factrial[i] = (i*factrial[i-1])%Mod;
    }
    printf("call lFactrial\n");
}
// 逆元の計算
void Inverse (int n, long Mod, long *factrial, long *inverse) {
    inverse[n] = lPow(factrial[n], (Mod-2))%Mod;     // フェルマーの小定理
    printf("call Inverse\n");
}
// nHkの計算
void  calc_nHk (int n, int k) {
    long Mod = lPow(10, 9)+7;
    long nHk;
    long *factrial, *inverse;
    factrial = (long *)malloc(sizeof(long)*(n+k));
    inverse = (long *)malloc(sizeof(long)*(n+k));
    lFactrial(n, Mod, factrial);
    //printf("call calc_nHk\n");
    Inverse(n, Mod, factrial, inverse);
    printf("call calc_nHk\n");
    // nHkの計算
    int N = n+k-1, K = n-1;
    nHk = factrial[N]*inverse[K]%Mod*inverse[N-K];
    // 出力
    printf("%ld\n", nHk);
    // メモリ解放
    free(factrial); free(inverse);
}

// メイン
int main(int argc, char const *argv[]) {
    // 変数
    int n, k;
    // 入力
    scanf("%d %d", &n, &k);
    // 階乗
    long *fact;
    fact = (long *)malloc(sizeof(long)*n);
    // 出力
    calc_nHk(n, k);
    return 0;
}
