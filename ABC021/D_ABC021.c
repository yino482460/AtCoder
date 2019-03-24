#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        m = m >> 1;
        n = (n*n)%Mod;
    }
    return ans;
}
// 逆元の計算
long Inverse (long x, long Mod, long *factrial) {
    return modlPow(factrial[x], (Mod-2), Mod);
}

// nHkの計算
void  calc_nHk (int n, int k) {
    // 計測
    //clock_t start, end;
    //start = clock();
    long Mod = lPow(10, 9)+7;
    long nHk;
    int N = n+k-1;
    long *factrial;
    factrial = (long *)malloc(sizeof(long)*(N+1));
    // 階乗・逆元計算
    factrial[0] = 1;
    for (size_t i = 1; i <= N; i++) {
        factrial[i] = lFactrial(i, Mod, factrial);
    }
    // nHkの計算
    nHk = factrial[n+k-1]*Inverse(n-1, Mod, factrial)%Mod*Inverse(k, Mod, factrial)%Mod;
    // 出力
    printf("%ld\n", nHk);
    //end = clock();
    //printf("%.4f秒かかりました\n",10*(double)(end-start)/CLOCKS_PER_SEC);
    // メモリ解放
    free(factrial);
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
