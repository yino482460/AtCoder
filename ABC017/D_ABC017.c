#include <stdio.h>
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
    long Mod;
    Mod = lPow(10, 8)+7;
    printf("%ld \n", Mod);
    return 0;
}
