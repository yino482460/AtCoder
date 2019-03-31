#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    int X;
    // 入力
    scanf("%d", &X);
    // 計算
    int ans;
    ans = X/10 + X%10;
    // 出力
    printf("%d\n", ans);
    return 0;
}
