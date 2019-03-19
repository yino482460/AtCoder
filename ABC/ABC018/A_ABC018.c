#include <stdio.h>
// メイン
int main(int argc, char const *argv[]) {
    // 変数
    int num[3], No[3] = {0};
    // 入力
    for (size_t i = 0; i < 3; i++) {
        scanf("%d", &num[i]);
    }
    // 判定
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (num[i] < num[j]) {
                No[i] ++;
            }
        }
    }
    // 出力
    for (size_t i = 0; i < 3; i++) {
        No[i] = No[i]+1;
        printf("%d\n", No[i]);
    }
    return 0;
}
