#include <stdio.h>

int main(int argc, char const *argv[]) {
    //変数の設定
    int H1, H2;
    int ans;
    //入力
    scanf("%d%d", &H1, &H2 );
    //計算
    ans = H1 - H2;
    //出力
    printf("%d\n", ans );
    return 0;
}
