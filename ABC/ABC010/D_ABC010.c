#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N_max 100
#define E_max N_max*(N_max-1)/2

int main(int argc, char const *argv[]) {
    // 変数
    int N, G, E;
    int ID[N_max];
    int a[E_max], b[E_max];
    // 入力
    scanf("%d %d %d", &N, &G, &E);
    for (size_t i = 0; i < N-1; i++) {scanf("%d", &ID[i] );}
    for (size_t i = 0; i < N; i++) {scanf("%d %d", &a[i], &b[i]);}

    return 0;
}
