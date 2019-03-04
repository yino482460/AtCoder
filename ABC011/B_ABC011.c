#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 大文字を小文字に変換
char toLow (char c) {
    if ((c>='A') && (c<='Z')) {
        return (c+0x20);
    } else {
        return c;
    }
}
// 小文字を大文字に変換
char toUp (char c) {
    if ((c>='a') && (c<='z')) {
        return (c-0x20);
    } else {
        return c;
    }
}

int main(int argc, char const *argv[]) {
    // 文字列
    char name[13];
    // 入力
    scanf("%s", name);
    int n = strlen(name);
    // 変換
    for (size_t i = 0; i < n; i++) {
        name[i] = toLow(name[i]);
    }
    name[0] = toUp(name[0]);
    // 出力
    printf("%s\n", name);
    return 0;
}
