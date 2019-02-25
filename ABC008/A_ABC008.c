#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    int S, T;
    // 入力
    scanf("%d %d", &S, &T );
    // 計算
    int ans = T-S+1;
    // 出力
    printf("%d\n", ans );
    return 0;
}
