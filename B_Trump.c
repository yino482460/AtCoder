#include <stdio.h>
#define String_max 10
char Trump[7] = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

int is_Match(char S[], char N[]) {
    int length = sizeof(Trump);
    int count = 0;
    // 文字列の数を計算
    for (size_t i = 0; i < String_max; i++) {
        if (N[i] != '\0') {
            count++;
        }
    }

    for (size_t i = 0; i < count; i++) {
        int j = 0;
        // 第 i文字が一致するか
        while ( j <= length ) {
            S[i] = Trump[j];
            if (S[i] == Trump[j]) {
                i ++;
            } else if ( j == length ) {
                return -1;  // 候補と不一致
            } else {
                j ++;   // 次の候補に移動
            }
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


    return 0;
}
