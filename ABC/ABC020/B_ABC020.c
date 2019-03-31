#include <stdio.h>
#include <string.h>
#define Sizechar 4
// 文字列を数字に変換
void charToDigit (char A[], char B[]) {
    int digit = 0, num[2*Sizechar];
    int lena, lenb;
    lena = strlen(A); lenb = strlen(B);
    // 文字列を数字に変換
    for (size_t i = 0; i < lena; i++) {
        num[i] = A[i] - '0';
    }
    for (size_t i = 0; i < lenb; i++) {
        num[lena+i] = B[i] - '0';
    }
    // 数値にする
    for (size_t i = 0; i < (lena+lenb); i++) {
        digit = digit*10 + num[i];
    }
    digit = 2*digit;
    printf("%d\n", digit);
}

// メイン
int main(int argc, char const *argv[]) {
    // 変数
    char A[Sizechar], B[Sizechar];
    // 入力
    scanf("%s %s", A, B);
    // 出力
    charToDigit(A, B);
    return 0;
}
