#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {
    // 変数
    int hour, minutes;
    // 入力
    scanf("%d %d", &hour, &minutes);
    // 計算
    double degree;
    degree = fabs(6*minutes - ((hour%12)*30 + 0.5*minutes));
    // 出力
    if (degree > 180) {
        printf("%lf\n", 360 - degree);
    } else {
        printf("%lf\n", degree);
    }
    return 0;
}
