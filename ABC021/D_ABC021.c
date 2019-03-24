#include <stdio.h>

// 二分累乗
long lPow (int n, int m) {
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

// メイン
int main(int argc, char const *argv[]) {
    // 変数
    int n, k;
    // 入力
    scanf("%d %d", &n, &k);


    return 0;
}
