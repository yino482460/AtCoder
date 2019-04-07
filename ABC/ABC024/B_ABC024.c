#include <stdio.h>
#define min(a, b) (a<b ? a:b)
// メイン
int main(int argc, char const *argv[]) {
    // 変数
    int N, T;
    scanf("%d %d", &N, &T);
    int A[N];
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    // 合計時間の計算
    long ans = 0;
    for (size_t i = 0; i < N-1; i++) {
        ans += min(T, A[i+1]-A[i]);
    }
    ans+=T;
    // 出力
    printf("%ld\n", ans);
    return 0;
}
