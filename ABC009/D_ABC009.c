#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define K_max 100
// 行列の用意
void setMatrix (int k, unsigned int C[], unsigned int Mat[][]) {
    // 行列の設定
    for (size_t i = 0; i < k; i++) {
        Mat[0][i] = C[i];    // 一行目
        if (i>=1) {Mat[i][i-1] = 1;}    // 対角線を埋める
    }
}
// 行列とベクトルのAND計算
void mulMatrixVector (int k, unsigned int Matrix[][], unsigned int Vector[]) {
    // 行列とベクトルのANDの計算
    for (size_t i = 0; i < k; i++) {
        for (size_t j = 0; j < k; j++) {
            Vector[i] ^= Matrix[i][j]&Vector[j];
        }
    }
}
// 行列同士の積
void mulMatrix (unsigned int A[][], unsigned int B[][], int n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            for (size_t k = 0; k < n; k++) {
                A[i][j] ^= A[i][k]&B[k][j];
            }
        }
    }
}
// 行列の階乗
unsigned int powMatrix (unsigned int C[],int k, int n) {
    unsigned int Matrix[K_max][K_max];
    unsigned int ans;
    // 行列の設定
    memset(Matrix, 0, sizeof(Matrix));  // 全部を0に設定
    setMatrix(k, C, Matrix);    // 漸化式の行列を設定
    if (n==0) {
        mulMatrixVector(k, Matrix, C);
        ans = C[0];
        return ans;
    } else if (n%2 == 0) {
        /* code */
    } else {
        /* code */
    }
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
