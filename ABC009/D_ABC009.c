#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define K_max 100
// 行列とベクトルのセット
unsigned int Matrix[K_max][K_max];
unsigned int Result[K_max];
unsigned int Vector[K_max];
// 行列の用意
void setMatrix (int k, unsigned int C[]) {
    // 行列の初期化
    memset(Matrix, 0, sizeof(Matrix));
    // 行列の設定
    for (size_t i = 0; i < k; i++) {
        Matrix[0][i] = C[i];    // 一行目
        if (i>=1) {Matrix[i][i-1] = 1;}    // 対角線を埋める
    }
}
// 行列とベクトルのAND計算
void mulMatrixVector (int k, unsigned int Matrix[][], unsigned int Vector[]) {
    // Result の初期化
    memset(Result, 0, sizeof(Result));
    // 行列とベクトルのANDの計算
    for (size_t i = 0; i < k; i++) {
        for (size_t j = 0; j < k; j++) {
            Result[i] ^= Matrix[i][j]&Vector[j];
        }
    }
}
// 行列同士の積
void malMatrix (unsigned int A[][], unsigned int B[][], int n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            for (size_t k = 0; k < n; k++) {
                A[i][j] ^= A[i][k]&B[k][j];
            }
        }
    }
}
// 行列の階乗
void powMatrix (unsigned int Matrix[][], int m, int k) {
    /* code */
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
