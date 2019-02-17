#include <stdio.h>
#include <string.h>
#define String_max 10
char keyword[7] = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

int is_keyword (char string) {
    int score = 0;
    int key_length = sizeof(keyword) / sizeof(keyword[0]);
    // @の場合は10点
    if (string == '@') {
        score = 10;
        return score;
    }
    // キーワードと一致すれば 1点
    for (size_t i = 0; i < key_length; i++) {
        if (string == keyword[i]) {
            score = 1;
            break;
        }
    }
    return score;
}

int is_Match(char S[], char N[]) {
    int S_length = 0;
    // 文字列の長さを計算
    S_length = strlen(S);
    // @の現れ方によって判定
    for (size_t i = 0; i < S_length; i++) {
        int check = 0;
        if (S[i] == N[i]) {
            continue;
        } else {
            check = is_keyword(S[i]) + is_keyword(N[i]);
            if ( check >= 11 ) {    // 11点以上であれば置換可能
                continue;
            } else {
                return -1;  // 置換不可
            }
            return -1;  // 不一致
        }
    }
    return 1;   // 一致
}

int main(int argc, char const *argv[]) {
    // 文字列
    char S[String_max+1], N[String_max+1];
    // 入力
    scanf("%s%s", S, N );
    // 判定
    if ( is_Match(S, N) == 1 ) {
        printf("You can win\n");
    } else {
        printf("You will lose\n");
    }
    return 0;
}
