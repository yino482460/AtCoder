#include <stdio.h>
#define N_max 100

int main(int argc, char const *argv[]) {
    // 変数
    int N;
    long C[N_max];
    // 入力
    scanf("%d", &N );
    for (size_t i = 0; i < N; i++) {
        scanf("%ld", &C[i] );
    }

    return 0;
}
