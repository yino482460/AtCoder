#include <stdio.h>
#include <string.h>
#define String_max 102

int main(int argc, char const *argv[]) {
    // 変数
    char A[String_max];
    // 入力
    scanf("%s", A);
    int length = strlen(A);
    // 出力
    if (length==1 && A[0]=='a') {
        printf("-1\n");
    } else {
        printf("a\n");
    }
    return 0;
}
