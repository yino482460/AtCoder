#include <stdio.h>
#define sizeS 101
#define sizeN 100
// 変数
int N, l[sizeN], r[sizeN];
// 文字列を反転
void ReverseStr (int n,char S[]) {
    char buf[sizeS];
    int len = r[n] - l[n];
    int no = r[n];
    for (size_t i = 0; i <= len; i++) {
        buf[i] = S[no];
        no --;
    }
    //printf("buf %s\n", buf);
    no = l[n];
    // 反転した文字列を元の文字列に接続
    for (size_t i = 0; i <= len; i++) {
        S[no] = buf[i];
        no ++;
    }
}
// メイン
int main(int argc, char const *argv[]) {
    // 文字列
    char S[sizeS];
    // 入力
    scanf("%s", S);
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &l[i], &r[i]);
        l[i]--; r[i]--;
    }
    // 反転
    for (size_t i = 0; i < N; i++) {
        ReverseStr(i, S);
    }
    // 出力
    printf("%s\n", S);
    return 0;
}
