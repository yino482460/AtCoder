#include <stdio.h>
#include <string.h>
#define sizeS 1001
// 文字列圧縮
void stringCompess (char str[]) {
    int len;
    len = strlen(str);
    int left = 0, right = left;
    // 圧縮
    while (1) {
        while (str[left] == str[right]) {
            right++;
        }
        printf("%c%d", str[left], right-left);
        left = right;
        if (right == len) {
            break;
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    // 変数
    char str[sizeS];
    // 入力
    scanf("%s", str);
    // 文字列圧縮
    stringCompess(str);
    return 0;
}
