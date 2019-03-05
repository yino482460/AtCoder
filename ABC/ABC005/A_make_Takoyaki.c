#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    int x, y;
    // 入力
    scanf("%d %d\n", &x, &y );
    // 計算
    int ans = 0;
    ans = y/x;
    // 出力
    printf("%d\n", ans );
    return 0;
}
