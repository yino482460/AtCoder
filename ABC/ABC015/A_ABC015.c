#include <stdio.h>
#include <string.h>
#define max_Size 51

int main(int argc, char const *argv[]) {
    // 変数
    char A[max_Size], B[max_Size];
    // 入力
    scanf("%s %s", A, B);
    // 計算
    int sizea, sizeb;
    sizea = strlen(A);
    sizeb = strlen(B);
    // 判定
    if (sizea > sizeb) {
        printf("%s\n", A);
    } else {
        printf("%s\n", B);
    }
    return 0;
}
