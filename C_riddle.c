#include <stdio.h>
long ans[3] = {-1, -1, -1};

// つるかめ算
int solve_equation(long population, int Legs) {
    int adults, olds, babys, legs;
    for (olds = 0; olds <= 1; olds++) {
        for (adults = 0; adults <= population-olds; adults++) {
            babys = population-(adults+olds);
            legs = 2*adults + 3*olds + 4*babys;
            if (legs == Legs) {
                ans[0] = adults; ans[1] = olds; ans[2] = babys;
                printf("%ld %ld %ld\n", ans[0], ans[1], ans[2] );
                return 0;   // 成功
            }
        }
    }
    printf("%ld %ld %ld\n", ans[0], ans[1], ans[2] );
    return -1;  // 失敗
}


int main(int argc, char const *argv[]) {
    // 変数
    long population;
    long legs;
    // 入力
    scanf("%ld", &population );
    scanf("%ld", &legs );
    // 出力
    solve_equation(population, legs);
    return 0;
}
