#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    int A, B, C, K;
    int child, adult;
    // 入力
    scanf("%d %d %d %d", &A, &B, &C, &K);
    scanf("%d %d", &child, &adult);
    // 計算
    int cost;
    if (K <= (child+adult)) {
        cost = (A*child+B*adult) - C*(child+adult);
    } else {
        cost = A*child+B*adult;
    }
    // 出力
    printf("%d\n", cost);
    return 0;
}
