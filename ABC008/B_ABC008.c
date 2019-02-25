#include <stdio.h>
#include <string.h>
#define N_max 51

int main(int argc, char const *argv[]) {
    // 変数
    int N;
    char S[N_max][N_max];
    int count[N_max] = {0};
    // 入力
    scanf("%d", &N );
    for (size_t i = 0; i < N; i++) {
        scanf("%s", S[i] );
    }
    // 比較
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if(strcmp(S[i],S[j])==0){
                count[i]++;
            }
        }
    }
    // 計算
    int max=0, i_max;
    for (size_t i = 0; i < N; i++) {
        if (count[i] > max) {
            max = count[i];
            i_max = i;
        }
    }
    // 出力
    printf("%s\n", S[i_max] );
    return 0;
}
