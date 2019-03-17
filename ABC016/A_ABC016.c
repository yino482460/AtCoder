#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    int M, D;
    // 入力
    scanf("%d %d", &M, &D);
    // 計算
    if (M%D == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
