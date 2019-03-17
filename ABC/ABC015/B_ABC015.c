#include <stdio.h>
#define sizeA 100

int main(int argc, char const *argv[]) {
    // 変数
    int N, ai, cnt = 0;
    int sum = 0;
    // 入力
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &ai);
        if (ai != 0) { cnt++; }
        sum += ai;
    }
    // 切り上げ
    int ans = (sum+cnt-1)/cnt;
    printf("%d\n", ans);
    return 0;
}
