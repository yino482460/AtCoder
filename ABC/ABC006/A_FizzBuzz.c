#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 入力
    int N;
    // 入力
    scanf("%d", &N );
    // 出力
    if (N%3 == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
