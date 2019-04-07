#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    char S[5];
    int N;
    // 入力
    scanf("%s\n", S);
    scanf("%d", &N);
    N--;
    // 出力
    printf("%c%c\n", S[N/5], S[N%5]);
    return 0;
}
