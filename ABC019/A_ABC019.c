#include <stdio.h>
#define min(a, b) (a<b ? a:b)
#define swap(a, b) (a+=b, b=a-b, a-=b)
// ソート

int main(int argc, char const *argv[]) {
    // 変数
    int a[3];
    // 入力
    for (size_t i = 0; i < 3; i++) {
        scanf("%d", &a[i]);
    }
    // ソート
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = i; j < 3; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    // 確認
    for (size_t i = 0; i < 3; i++) {
        printf("%2d", a[i]);
    }
    printf("\n");
    // 出力
    printf("%d\n", a[1]);
    return 0;
}
