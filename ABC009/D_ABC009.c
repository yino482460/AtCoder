#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define K_max 100
// 変数
int K; long M;
unsigned int A[K_max], C[K_max];
// 行列の用意
void setMatrix (unsigned int C[], unsigned int Mat[][]) {
    // 行列の設定
    for (size_t i = 0; i < K; i++) {
        Mat[0][i] = C[i];    // 一行目
        if (i>=1) {Mat[i][i-1] = ~0;}    // 対角線を埋める
    }
}
// 行列とベクトルのAND計算
void mulMatrixVector (unsigned int Matrix[][], unsigned int Vector[]) {
    for (size_t i = 0; i < K; i++) {
        for (size_t j = 0; j < K; j++) {
            Vector[i] ^= Matrix[i][j]&Vector[j];
        }
    }
}
// 行列同士のAND計算
void mulMatrix (unsigned int A[][], unsigned int B[][]) {
    for (size_t i = 0; i < K; i++) {
        for (size_t j = 0; j < K; j++) {
            for (size_t k = 0; k < K; k++) {
                A[i][j] ^= A[i][k]&B[k][j];
            }
        }
    }
}
// 行列の階乗
unsigned int powMatrix (unsigned int Matrix[][], int factorial) {
    if (factorial==0) {
        return Matrix;
    } else if (factorial%2 == 0) {
        powMatrix(mulMatrix(Matrix, Matrix), factorial/2);
    } else {
        mulMatrix(Matrix, powMatrix(Matrix, factorial-1));
    }
}
// 漸化式の計算
unsigned int Solve () {
    int factorial = M-K;
    // 初項の設定
    unsigned int Matrix[K_max][K_max];
    setMatrix(C, Matrix);    // 漸化式の行列を設定

}

int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d %ld", &K, &M );
    for (size_t i = 0; i < K; i++) {
        scanf("%d", &A[K-i-1] );
    }
    for (size_t i = 0; i < K; i++) {
        scanf("%d", &C[i] );
    }
    // 計算

    return 0;
}
