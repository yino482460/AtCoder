#include <stdio.h>
#include <stdlib.h>
int InPut();
int LCA(int N, int Q, int x[], int y[], int a[], int b[]);

int main(int argc, char const *argv[]) {
    InPut();



    return 0;
}

// 入力
int InPut () {
    // 変数
    int N, Q;
    int *x, *y, *a, *b;
    // 入力
    scanf("%d", &N);
    x = (int*)malloc(sizeof(int)*N);
    y = (int*)malloc(sizeof(int)*N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    scanf("%d", &Q);
    a = (int*)malloc(sizeof(int)*Q);
    b = (int*)malloc(sizeof(int)*Q);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    LCA(N, Q, x, y, a, b);
    return 0;
}
// LCA (n) バージョン
int LCA (int N, int Q, int x[], int y[], int a[], int b[]) {
    

    return 0;
}
