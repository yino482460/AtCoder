#include <stdio.h>
#include <stdlib.h>
// 判定
void isShortestRoute (int a, int b, int K, int *P) {
    P[K] = a; P[K+1] = b;
    for (size_t i = 0; i < K+2; i++) {
        for (size_t j = 0; j < K+2; j++) {
            if (i == j) {
                continue;
            }
            if (P[i] == P[j]) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}

int main(int argc, char const *argv[]) {
    // 変数
    int N, a, b;
    int K;
    int *P;
    // 入力
    scanf("%d %d %d", &N , &a, &b);
    scanf("%d", &K);
    P = (int *)malloc(sizeof(int)*(K+2));
    for (size_t i = 0; i < K; i++) {
        scanf("%d", &P[i]);
    }
    // 判定
    isShortestRoute(a, b, K, P);
    return 0;
}
