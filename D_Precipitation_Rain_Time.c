#include <stdio.h>
#include <string.h>

#define N_max 60002

int main(int argc, char const *argv[]) {
    //入力
    int N, i;
    int S[N_max], E[N_max];
    scanf("%d", &N );
    //時刻の読み込み
    for (i = 0; i < N; i++) {
        scanf("%d-%d", &S[i], &E[i] );
    }

    //出力
    for ( i = 0; i < N; i++) {
        printf("%d %d\n", S[i], E[i] );
    }
    return 0;
}
