#include <stdio.h>
#define sizeA 200001
// 横に移動(本質的にはSwap)
void Move(int a[], int b[]) {
    int tmp;
    tmp = *a; *a = *b; *b = tmp;
}

int main(int argc, char const *argv[]) {
    // 変数
    long N, M, D;
    int A[sizeA];
    // 入力
    scanf("%ld %ld %ld", &N, &M, &D);
    for (size_t i = 0; i < M; i++) {
        scanf("%d", &A[i]);
    }
    return 0;
}
