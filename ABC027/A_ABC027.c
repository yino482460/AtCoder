#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    int l1, l2, l3;
    // 入力
    scanf("%d %d %d", &l1, &l2, &l3);
    // 計算
    if (l1 == l2) {
        printf("%d\n", l3);
    } else if (l1 == l3) {
        printf("%d\n", l2);
    } else if (l2 == l3) {
        printf("%d\n", l1);
    }
    return 0;
}
