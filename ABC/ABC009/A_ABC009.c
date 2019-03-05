#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    int N;
    // 入力
    scanf("%d", &N );
    // 計算
    int ans;
    ans = (N%2==0 ? N/2:N/2+1);
    // 出力
    printf("%d\n", ans );
    return 0;
}
