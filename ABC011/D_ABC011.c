#include <stdio.h>
double getNumOfCombination (int N, int X, int Y, int horizon) {
    int right = X+(horizon-X)/2;
    int left = (horizon-X)/2;
    int vertical = N-horizon;
    int up = Y+(vertical-Y)/2;
    int down = (vertical-Y)/2;
}
// 判定
double Jump (int N, int D, int X, int Y) {
    double probability = 0;
    if (X%D!=0 || Y%D!=0) {
        probability = 0;
        return probability;
    }
    int nx = X/D;
    int ny = Y/D;
    if (nx+ny > N) {
        probability = 0;
        return probability;
    }
    for (int horizon = 0; horizon <= N; horizon++) {
        
    }

    return probability;
}



int main(int argc, char const *argv[]) {
    // 変数
    long N, D;
    long X, Y;
    // 入力
    scanf("%ld %ld", &N, &D );
    scanf("%ld %ld", &X, &Y );
    return 0;
}
