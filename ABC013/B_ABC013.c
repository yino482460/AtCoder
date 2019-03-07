#include <stdio.h>
#define min(a, b) (a<b ? a:b)
// 次の数字を調べる
int NextDigit (int num) {
    if (num == 9) {
        return 0;
    } else {
        return num+1;
    }
}
// 最小操作回数を調べる
int Distancel (int a, int b) {
    int res = 0;
    while (a != b) {
        ++res;
        a = NextDigit(a);
    }
    res = min(res, 10-res);
    return res;
}

int main(int argc, char const *argv[]) {
    // 変数
    int a, b;
    // 入力
    scanf("%d %d", &a, &b );
    // 計算
    int ans = Distancel(a, b);
    // 出力
    printf("%d\n", ans );
    return 0;
}
