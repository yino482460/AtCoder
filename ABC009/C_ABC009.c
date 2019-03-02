#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define string_MAX 101
#define min(a, b) (a<b ? a:b)

void sort_String (int N, int K, char str[]) {
    char T[N+1];
    int count_s[26] = {0}, count_t[26] = {0};
    // 文字列に出てくるアルファベットの数を計算
    for (size_t i = 0; i < N; i++) {
        count_s[str[i] - 'a'] ++;
        count_t[str[i] - 'a'] ++;
    }
    // 並び替え
    for (size_t i = 0; i < N; i++) {
        for (size_t index = 0; index < 26; index++) {
            if (count_t[index] == 0) { continue;} //含まれていないなら無視
            char c = 'a' + index;
            int different = 0;  // 不一致の数
            for (size_t j = 0; j < i; j++) {
                if (str[j] != T[j]) {different ++;} // i-1文字目までの不一致の数
            }
            if (c != str[i]) {different ++;}    // i文字目で不一致かどうか
            count_s[str[i] - 'a'] --;
            count_t[index] --;
            int number = (N-1)-i;   // 残りの文字数
            for (size_t j = 0; j < 26; j++) {
                number-=min(count_s[j],count_t[j]);
            }
            different += number;
            if (different <= K) {
                T[i] += ('a'+index);
                break;
            }
            ++count_s[str[i]-'a'];
			++count_t[index];
        }
    }
    printf("%s\n", T );
}

int main(int argc, char const *argv[]) {
    // 文字列
    int N, K;
    char S[string_MAX];
    // 入力
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    // 出力
    sort_String(N, K, S);
    return 0;
}
