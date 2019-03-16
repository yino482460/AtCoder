#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    int a, b;
    // 入力
    scanf("%d %d", &a, &b);
    // 計算
    int ans = b-a%b;
    ans = (ans==b ? 0:ans);
    // 出力
    printf("%d\n", ans);
    return 0;
}
