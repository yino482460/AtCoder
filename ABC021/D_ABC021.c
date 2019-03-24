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
// 逆元の計算
void Inverse (int n, long Mod, long *factrial, long *inverse) {
    inverse[n] = lPow(factrial[n], (Mod-2))%Mod;     // フェルマーの小定理
    printf("call Inverse\n");
}
// nHkの計算
void  calc_nHk (int n, int k) {
    long Mod = lPow(10, 9)+7;
    long nHk;
    int N = n+k-1, K = n-1;
    long *factrial, *inverse;
    factrial = (long *)malloc(sizeof(long)*(n+k));
    inverse = (long *)malloc(sizeof(long)*(n+k));
    for (size_t i = 0; i < N; i++) {
        factrial[i] = lFactrial(i, Mod, factrial);
    }
    // デバッグ
    for (int i = 0; i < N; i++) {
        printf("%3d:%ld\n", i, factrial[i]);
    }
    //printf("call calc_nHk\n");
    //Inverse(N, Mod, factrial, inverse);
    printf("call calc_nHk\n");
    /*
    // nHkの計算
    nHk = factrial[N]*inverse[K]%Mod*inverse[N-K];
    */
    // 出力
    //printf("%ld\n", nHk);
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
