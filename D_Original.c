#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_Box 2001
#define Marbles 901
#define Infinity 100000000
// 変数
long dp[Max_Box][Marbles];
int R, G, B;
int sum;
int Base[3] = {-100, 0, 100};
// マーブルの最小移動手数を計算する関数
int calc_Move_Cost (int left, int base, int marbles) {
    int min_trouble = 0;
    int right = base + marbles - abs(base-left);    // 右側の座標
    // 最小移動手数
    min_trouble = 0.5*abs(left-base)*abs(left-base-1);  // 左側
    min_trouble += 0.5*abs(right-base)*abs(right-base-1);   // 右側
    return min_trouble;
}



int main(int argc, char const *argv[]) {
    // 入力
    //scanf("%d %d %d", &R, &G, &B);
    //sum = R+G+B;
    // dpに初期値を設定
    //memset(dp,-1,sizeof(dp));
    // 出力
    printf("%d\n", calc_Move_Cost(-101, -100, 2) );
    return 0;
}
