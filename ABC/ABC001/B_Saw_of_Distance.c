#include <stdio.h>

int main(int argc, char const *argv[]) {
    //変数
    double m;   // Distance
    double vv;
    //入力
    scanf( "%lf", &m);
    //計算
    m = m*0.001;        // kmに換算
    //条件分岐 計算
    if (m < 0.1) {
        vv = 0;
    } else if ( (m >= 0.1) && (m <= 5) ) {
        vv = m*10;
    } else if ( (m >= 6) && (m <= 30) ) {
        vv = m+50;
    } else if ( (m >= 35) && (m <= 70) ) {
        vv = (m - 30)/5 + 80;
    } else {
        vv = 89;
    }
    //出力
    printf("%02d\n", (int)vv );
    return 0;
}
