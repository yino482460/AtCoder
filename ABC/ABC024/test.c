#include <stdio.h>
#define Mod 50

int main(int argc, char const *argv[]) {
    // 変数
    int a = 9, b = 2;
    printf("%d\n", a%Mod-b%Mod);
    printf("%d\n", (a-b+Mod)%Mod);
    return 0;
}
