#include <stdio.h>
#define String_max 10
char AtCoder[8] = {'a', 't', 'c', 'o', 'd', 'e', 'r', '\0'};

int is_keyword (char string) {
    int hash = 0;
    int key_length = sizeof(AtCoder) / sizeof(AtCoder[0]);
    // @の場合は10点
    if (string == '@') {
        hash = 10;
    }
    // キーワードと一致すれば 1点
    for (size_t i = 0; i < key_length; i++) {
        if (string == AtCoder[i]) {
            hash = 1;
            break;
        }
    }
    return hash;
}

int is_Match(char S[], char N[]) {
    int S_length = 0;
    // 文字列の長さを計算
    for (size_t i = 0; i < String_max; i++) {
        if (S[i] != '\0') {
            S_length ++;
        }
    }
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
                return -1;
            }
            return -1;
        }
    }
    return 1;   // 一致
}

int main(int argc, char const *argv[]) {
    // 変数
    char S[String_max+1], N[String_max+1];
    // 入力
    scanf("%s", S );
    scanf("%s", N );
    // 判定
    if (  is_Match(S, N) == -1 ) {
        printf("You will lose\n");
    } else {
        printf("You can win\n");
    }
    return 0;
}
