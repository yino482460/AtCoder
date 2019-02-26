#include <stdio.h>
#define N_max 100
int N;
// 期待値の計算
double all_Search (int num[]) {
    // 階乗の計算
    long factorial = 1;
    for (int i = 1; i <= N; i++) {
        factorial = factorial*i;
    }
    // 総当たり

    double expected_value = 0;


    return expected_value;
}

int main(int argc, char const *argv[]) {
    // 変数
    int C[N_max];
    // 入力
    scanf("%d", &N );
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &C[i] );
    }
    return 0;
}
