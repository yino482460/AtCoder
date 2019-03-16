#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    char X;
    // 入力
    scanf("%c", &X);
    // 計算
    int ans;
    ans = X-'A'+1;
    // 出力
    printf("%d\n", ans);
    return 0;
}
