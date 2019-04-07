#include <stdio.h>
#define Nmax 21

int main(int argc, char const *argv[]) {
    // 変数
    int N;
    // 入力
    int Boss[Nmax] = {0};
    scanf("%d\n", &N);
    for (size_t i = 1; i <= N; i++) {
        int boss;
        scanf("%d", &boss);
        boss--;
        Boss[i] = boss;
    }
    // 確認
    for (size_t i = 0; i < N; i++) {
        printf("%d\n", Boss[i]);
    }
    return 0;
}
