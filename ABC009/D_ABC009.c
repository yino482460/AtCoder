#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define K_max 100
// 行列とベクトルのセット
unsigned int Matrix[K_max][K_max];
void set_Matrix_Vector (int k, long m, unsigned int A[], unsigned int C[]) {
    // 行列の初期化
    memset(Matrix, 0, sizeof(Matrix));
    // 行列の設定
    for (size_t i = 0; i < k; i++) {    // 一行目
        Matrix[0][i] = C[i];
    }
    for (size_t i = 1; i < k; i++) {    // 対角線を埋める
        Matrix[i][i-1] = 1;
    }

}

// 行列の計算
int calc_Recurrence_Formula (int k, long m, unsigned int A[], unsigned int C[]) {
    unsigned int ans = 0;


    return ans;
}

int main(int argc, char const *argv[]) {
    // 変数
    int K; long M;
    unsigned int A[K_max], C[K_max];
    // 入力
    scanf("%d %ld", &K, &M );
    for (size_t i = 0; i < K; i++) {
        scanf("%d", &A[i] );
    }
    for (size_t i = 0; i < K; i++) {
        scanf("%d", &C[i] );
    }
    // 計算

    return 0;
}
