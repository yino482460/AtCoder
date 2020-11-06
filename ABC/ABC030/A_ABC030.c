#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    double A, B, C, D;
    scanf("%lf %lf %lf %lf", &A, &B, &C, &D);
    // 判定
    if (B/A > D/C) {
        printf("TAKAHASHI\n");
    } else if (B/A == D/C) {
        printf("DRAW\n");
    } else {
        printf("AOKI\n");
    }
    return 0;
}
