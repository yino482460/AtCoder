#include <stdio.h>

// 二分累乗
long lPow (int n, int m) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return n;
    } else if (n%2 == 0) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return lPow(n, m-1)*n;
    }
}

// メイン
int main(int argc, char const *argv[]) {
    // 変数

    return 0;
}
