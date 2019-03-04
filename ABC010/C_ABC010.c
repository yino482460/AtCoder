#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define n_MAX 1000
#define eps -0.0001
// 三平方の定理
double Distance (int xa, int ya, int xb, int yb) {
    double distance;
    int x = abs(xa-xb);
    int y = abs(ya-yb);
    distance = sqrt(x*x+y*y);
    return distance;
}
// 判定
int Check (int n, int txa, int tya, int txb, int tyb, int X[], int Y[], int T, int V) {
    // 判定
    for (size_t i = 0; i < n; i++) {
        int distance1 = Distance(txa, X[i], tya, Y[i]);
        int distance2 = Distance(X[i], txb, Y[i], tyb);
        if (T*V+eps >= distance1+distance2) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}

int main(int argc, char const *argv[]) {
    // 変数
    int txa, tya, txb, tyb, T, V;
    int n;
    int X[n_MAX], Y[n_MAX];
    // 入力
    scanf("%d %d %d %d %d %d", &txa, &tya, &txb, &tyb, &T, &V);
    scanf("%d", &n );
    for (size_t i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
    }
    // 判定
    Check(n, txa, tya, txb, tyb, X, Y, T, V);
    return 0;
}
