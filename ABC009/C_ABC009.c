#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define string_MAX 101

void sort_String (int N, int K, char str[]) {
    char T[N+1];
    int count_s[26] = {0}, count_t[26] = {0};
    // 文字列に使われているアルファベットの数を計算
    for (size_t i = 0; i < N; i++) {
        count_s[str[i] - 'a'] ++;
        count_t[str[i] - 'a'] ++;
    }
    // 並び替え
    for (size_t i = 0; i < N; i++) {
        for (size_t index = 0; index < 26; index++) {
            if (count_t[i] == 0) { continue;} //含まれていないなら無視
            
        }
    }

}

int main(int argc, char const *argv[]) {
    // 文字列
    int N, K;
    char S[string_MAX];
    // 入力
    scanf("%d %d", &N, &K);
    scanf("%s", S);

    return 0;
}
