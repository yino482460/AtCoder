#include <stdio.h>
// プラスマイナス判定
void Judge(int A, int B, int C) {
    int plus = A+B;
    int minus = A-B;
    if ( plus==C && minus==C ) {
        printf("?\n");
    } else if (plus==C && minus!=C) {
        printf("+\n");
    } else if (plus!=C && minus==C) {
        printf("-\n");
    } else {
        printf("!\n");
    }
}
int main(int argc, char const *argv[]) {
    // 変数
    int A, B, C;
    // 入力
    scanf("%d %d %d", &A, &B, &C);
    // 出力
    Judge(A, B, C);
    return 0;
}
