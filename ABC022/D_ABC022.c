#include <stdio.h>
#include <stdlib.h>
// 座標
typedef struct point {
    int x, y;
} point_t;
// 入力

int main(int argc, char const *argv[]) {
    // 変数
    int N;
    scanf("%d", &N);
    point_t *A, *B;
    // 入力
    A = (point_t *)malloc(sizeof(point_t)*N);
    B = (point_t *)malloc(sizeof(point_t)*N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &A[i].x, &A[i].y);
    }
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &B[i].x, &B[i].y);
    }

    return 0;
}
