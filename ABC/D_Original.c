#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Infinity 10000000
#define Left_min -300
#define Right_max 300
#define min(a, b) (a<=b ? a:b)
#define max(a, b) (a>=b ? a:b)
// 変数
int R, G, B;
int sum;
int Base[3] = {-100, 0, 100};   // R:0 G:1 B:2
// マーブルの移動コスト
long Move_Cost (int left, int base, int marbles) {
    int cost = 0;
    int right = left + marbles - 1;    // 右側の座標
    // 最小移動手数
    cost += 0.5*abs(left-base)*abs(left-base-1);  // 左側
    cost += 0.5*abs(right-base)*abs(right-base+1);   // 右側
    return cost;
}
// マーブルの最小移動コスト
long min_Move_Cost (int R, int G, int B) {
    long min_cost = Infinity;
    // 各石の開始位置
    int R_right = Base[0] + R/2;
    int  G_left, G_right;
    int B_left = Base[2] - B/2;
    // 各石の配置コスト
    long R_cost, G_cost, B_cost, sum_cost;
    // 総当たり
    int r, g, b;
    for (G_left = Left_min; G_left < Right_max; G_left++) {
        // Rの開始位置
        r = min(R_right, G_left);   // Rの右端を計算
        r = r-R+1;   // Rの左端の計算
        // Gの開始位置
        g = G_left;
        G_right = g+G;
        // Bの開始位置
        b = max(G_right, B_left);
        // 各コストの計算
        R_cost = Move_Cost(r, Base[0], R);
        G_cost = Move_Cost(g, Base[1], G);
        B_cost = Move_Cost(b, Base[2], B);
        // 最小コストの計算
        sum_cost = R_cost + G_cost + B_cost;
        min_cost = min(min_cost, sum_cost);
    }
    return min_cost;
}


int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d %d %d", &R, &G, &B);
    // 出力
    printf("%ld\n", min_Move_Cost(R, G, B) );
    return 0;
}
