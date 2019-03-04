#include <stdio.h>
// 確率版コンビネーションを計算
double Combi (int n, int r) {
    double ans = 0;

    return ans;
}

// 各場合の確率
double getNumOfCombination (int N, int X, int Y, int horizon) {
    int vertical = N-horizon;
    if ((horizon-X)%2 != 0) { return 0;}
    if ((vertical-Y)%2 != 0) { return 0;}
    int right = X+(horizon-X)/2;
    int up = Y+(vertical-Y)/2;
    if (right<0 || up<0) { return 0;}
    // 確率
    double p = 1;
    p *= Combi(N, horizon);
    p *= Combi(horizon, right);
    p *= Combi(vertical, up);
    return p;
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
