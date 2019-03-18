#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    int s[3], e[3];
    // 入力
    for (size_t i = 0; i < 3; i++) {
        scanf("%d %d", &s[i], &e[i]);
    }
    // 計算
    int sum = 0;
    for (size_t i = 0; i < 3; i++) {
        sum += s[i]*0.1*e[i];
    }
    // 出力
    printf("%d\n", sum);
    return 0;
}
