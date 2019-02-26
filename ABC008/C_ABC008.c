#include <stdio.h>
#define N_max 100
// あるコインが表になる確率
double calc_probability (int num) {
    double probability = 0;
    if (num%2 == 1) {
        probability = 0.5;
    } else {
        probability = (num+2)/(2*num+2);
    }
    return probability;
}
// 期待値の計算
double calc_expected_value (int N, int num[]) {
    // 期待値
    double expected_value = 0;
    for (size_t i = 0; i < N; i++) {
        expected_value += calc_probability(num[i]);
    }
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
    // 出力
    printf("%lf\n", calc_expected_value(N, C) );
    return 0;
}
