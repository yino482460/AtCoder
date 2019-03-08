#include <stdio.h>
#define sizeN 100002
#define sizeA 200001
#define Swap(a, b) (a+=b, b=a-b, a=a-b)
// 阿弥陀の到達位置を調べる
int Amida (long N, long M, long D, int A[]) {
    int Amida[sizeN];
    // 初期配置
    for (int i = 1; i <= N; i++) {
        Amida[i] = i;
    }
    for (size_t i = 0; i <= N; i++) {
        printf("%d ", Amida[i] );
    }
    printf("\n");
    // 阿弥陀の答えを計算 D=1
    for (int i = 0; i < M; i++) {
        Swap(Amida[A[i]], Amida[A[i]+1]);
    }
    for (size_t i = 0; i <= N; i++) {
        printf("%d ", Amida[i] );
    }
    printf("\n");
    return 0;
}

int main(int argc, char const *argv[]) {
    // 変数
    long N, M, D;
    int A[sizeA];
    // 入力
    scanf("%ld %ld %ld", &N, &M, &D);
    for (int i = 0; i < M; i++) {
        scanf("%d", &A[i]);
    }
    Amida(N, M, D, A);
    return 0;
}
