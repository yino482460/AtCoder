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
            ans *= n;
            ans %= Mod;
        }
        m = m/2;
        ans = (ans*ans)%Mod;
    }
    return ans;
}

// nHkの計算
void  calc_nHk (int n, int k) {
    long Mod = lPow(10, 9)+7;
    long nHk;
    int N = n+k-1;
    long *factrial, *inverse;
    factrial = (long *)malloc(sizeof(long)*(n+k+1));
    inverse = (long *)malloc(sizeof(long)*(n+k+1));
    // 階乗計算
    for (size_t i = 0; i <= N; i++) {
        factrial[i] = lFactrial(i, Mod, factrial);
    }
    // 逆元の計算
    for (size_t i = 0; i <= N; i++) {
        inverse[i] = modlPow(factrial[i], (Mod-2), Mod);
    }
    // デバッグ
    for (int i = 0; i < N; i++) {
        printf("%2d:%ld\n", i, inverse[i]);
    }
    // nHkの計算
    nHk = (factrial[n+k-1]*inverse[n-1]*inverse[k])%Mod;
    // 出力
    printf("Mod %ld ans %ld\n", Mod, nHk);
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
