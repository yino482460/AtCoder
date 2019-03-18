#include <stdio.h>
#define sizeF 100001
// 二分累乗
long lPow(int n, int m) {
    if (m == 0) {
        return n;
    } else if (m%2 == 2) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return n*lPow(n, m-1);
    }
}

int main(int argc, char const *argv[]) {
    // 変数
    int N, M;
    int flaver[sizeF];
    // 入力
    scanf("%d %d", &N, &M);
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &flaver[i]);
    }
    return 0;
}
