#include <stdio.h>
#define Max 101
#define Soled 1
#define Disposal -1

int is_sold (int T, int N, int M, int A[], int B[]) {
    int N_count = 0;    // 探索したタコ焼きの個数
    int i, j;
    for ( i = 0; i < M; i++) {
        for (j = N_count; j < N; j++) {
            if ((B[i] - A[j])<=T && A[j]<=B[i]) {
                N_count = j+1;
                break;
            }
        }
        if (j == N) {
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
    return 0;
}

int main(int argc, char const *argv[]) {
    // 変数
    int T, N, M;
    int A[Max], B[Max];
    // 入力
    scanf("%d", &T );
    scanf("%d", &N );
    for (size_t i = 0; i < N; i++) {scanf("%d", &A[i] );}
    scanf("%d", &M );
    for (size_t i = 0; i < M; i++) {scanf("%d", &B[i] );}
    // 判定
    is_sold(T, N, M, A, B);
    return 0;
}
