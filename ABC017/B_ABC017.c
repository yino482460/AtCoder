#include <stdio.h>
#include <string.h>
#define sizeS 51
// 判定
void JudgeChoku (char str[]) {
    int len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        if (str[i]!='c' && str[i]!='h' && str[i]!='o' && str[i]!='k' && str[i]!='u') {
            printf("NO\n");
            return;
        } else if ((str[i]=='c' && str[i+1]!='h') || (str[i-1]!='c' && str[i]=='h')) {
            printf("NO\n");
            return;
        } else if (i == len-1) {
            printf("YES\n");
        }
    }
}

int main(int argc, char const *argv[]) {
    // 変数
    char S[sizeS];
    // 入力
    scanf("%s", S);
    // 出力
    JudgeChoku(S);
    return 0;
}
