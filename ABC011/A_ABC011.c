#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    int N, ans;
    // 入力
    scanf("%d", &N );
    // 出力
    if (N==12) {
        ans =1;
        printf("%d\n", ans );
    } else {
        printf("%d\n", N+1 );
    }
    return 0;
}
