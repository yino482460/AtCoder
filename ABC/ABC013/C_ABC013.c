#include <stdio.h>
#define max(a, b) (a>b ? a:b)
#define min(a, b) (a<b ? a:b)
// 食いだめ
long Eat (long N, long H, long A, long B, long C, long D, long E) {
    long money = 10000000000000;
    // 探索
    for (long normal = 0; normal <= N; normal++) {
        long fasting = N-normal; // 断食日数
        long satisfy = H+B*normal;   // 満腹度
        long simple = max((E*fasting+D+E-satisfy)/(D+E), 0);
        money = min(money, A*normal+C*simple);
    }
    return money;
}

int main(int argc, char const *argv[]) {
    // 変数
    long N, H;
    long A, B, C, D, E;
    // 入力
    scanf("%ld %ld", &N, &H);
    scanf("%ld %ld %ld %ld %ld", &A, &B, &C, &D, &E);
    // 計算
    long ans = Eat(N, H, A, B, C, D, E);
    // 出力pr
    printf("%ld\n", ans );
    return 0;
}
