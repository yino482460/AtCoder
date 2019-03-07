#include <stdio.h>
#define max(a, b) (a>b ? a:b)
#define min(a, b) (a<b ? a:b)
// 食いだめ
int Eat (int N, int H, int A, int B, int C, int D, int E) {
    int money = 10000000;
    // 探索
    for (int normal = 0; normal <= N; normal++) {
        int fasting = N-normal; // 断食日数
        int satisfy = H+B*normal;   // 満腹度
        int simple = max((E*fasting+D+E-satisfy)/(D+E), 0);
        money = min(money, A*normal+C*simple);
    }
    return money;
}

int main(int argc, char const *argv[]) {
    // 変数
    int N, H;
    int A, B, C, D, E;
    // 入力
    scanf("%d %d", &N, &H);
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
    // 計算
    int ans = Eat(N, H, A, B, C, D, E);
    // 出力pr
    printf("%d\n", ans );
    return 0;
}
