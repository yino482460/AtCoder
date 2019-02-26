#include <stdio.h>
#define N_max 100
// 期待値の計算
double all_Search (int N, int num[]) {
    // 階乗の計算
    long factorial = 1;
    for (int i = 1; i <= N; i++) {
        factorial = factorial*i;
    }
    // 総当たり
    int here = 0;
    int count = 0;  // 条件を満たす個数
    int look = here+1;
    while (look == N) {
        if (num[look]%num[here] == 0) {
            count++;
        }
        look++;
    }

    double expected_value = 0;
    expected_value = count/factorial;
    return expected_value;
}

int main(int argc, char const *argv[]) {
    // 変数
    int C[N_max];
    int N;
    // 入力
    scanf("%d", &N );
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &C[i] );
    }
    return 0;
}
