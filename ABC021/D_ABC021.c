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
}
// 階乗の計算
long lFactrial (int n, long Mod, long *factrial) {
    long ans;
    if (n == 0) {
        return 1;;
    }
    ans = (n*factrial[n-1])%Mod;
    return ans;
}
// 累乗の割り算
long modlPow (long n, long m, long Mod) {
    long ans = 1;
    while (m) {
        if (m&1) {
            ans = (ans*n)%Mod;
        }
        m = m/2;
        n = (n*n)%Mod;
    }
    return ans;
}

// nHkの計算
void  calc_nHk (int n, int k) {
    long Mod = lPow(10, 9)+7;
    long nHk;
    int N = n+k-1;
    long *factrial, *inverse;
    factrial = (long *)malloc(sizeof(long)*(N+1));
    inverse = (long *)malloc(sizeof(long)*(N+1));
    // 階乗・逆元計算
    factrial[0] = 1; inverse[0] = 1;
    for (size_t i = 1; i <= N; i++) {
        factrial[i] = lFactrial(i, Mod, factrial);
        inverse[i] = modlPow(factrial[i], (Mod-2), Mod);
    }
    // nHkの計算
    nHk = factrial[n+k-1]*inverse[n-1]%Mod*inverse[k]%Mod;
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
    // 出力
    calc_nHk(n, k);
    return 0;
}
