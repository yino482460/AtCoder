#include <stdio.h>
#include <stdlib.h>
#define Rmax 500
#define sizeC 500

int main(int argc, char const *argv[]) {
    // 変数
    int R, C, K;
    char **s;
    // 入力
    scanf("%d %d %d", &R, &C, &K);
    // 文字列の領域を確保
    s = (char **)malloc(sizeof(char *)*R);
    for (size_t i = 0; i < R; i++) {
        s[i] = (char *)malloc(sizeof(char)*(C+1));
        scanf("%s", s[i]);  // 文字列を取得
    }

    return 0;
}
