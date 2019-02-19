#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Infinity 10000000
#define Left_min -300
#define Right_max 300
// 変数
int R, G, B;
int sum;
int Base[3] = {-100, 0, 100};
// マーブルの移動コストを計算する関数
long Move_Cost (int left, int base, int marbles) {
    int cost = 0;
    int right = base + marbles - abs(base-left);    // 右側の座標
    // 最小移動手数
    cost = 0.5*abs(left-base)*abs(left-base-1);  // 左側
    cost += 0.5*abs(right-base)*abs(right-base-1);   // 右側
    return cost;
}
// マーブルの最小移動コストを総当たりで計算する
long calc_min_Move_Cost (int R, int G, int B) {
    long min_cost = Infinity;
    // 緑の配置から考える
    int G_right = G/2 + Base[1];
    int G_left = Base[1] - G/2;
    long  G_cost = Move_Cost(G_left ,Base[1], G);
    // 赤の配置を考慮する
    int R_right = R/2 + Base[0];
    int R_left = Base[0] - R/2;
    long  R_cost = Move_Cost(R_left ,Base[0], R);
    if (R_right >= G_left) { // 赤と緑の配置が被る場合の探索
        // 限界まで左に寄せる
        R_left = Left_min; G_left = R_left+R+1;
        for (int i = Base[1]; i < Base[2]; i++) {
            for (int j = Left_min; j < Base[0]; j++) {
                R_left++; G_left++;
                R_cost = Move_Cost(R_left, Base[0], R);
                G_cost = Move_Cost(G_left, Base[1], G);
                if ((R_cost+G_cost) < min_cost) {   // 更新
                    min_cost = R_cost+G_cost;
                    G_right = G + G_left;
                }
            }
        }
    } else {
        min_cost = R_cost+G_cost;
    }
    // 青の配置を考慮
    int B_left = Base[2] - B/2;
    long  B_cost = 0;
    if (G_right >= B_left) { // 青と緑の配置が被る場合の探索
        B_cost = Move_Cost(G_right+1 ,Base[2], B);
    } else {
        B_cost = Move_Cost(B_left ,Base[2], B);
    }
    min_cost += B_cost;

    return min_cost;
}


int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d %d %d", &R, &G, &B);
    // 出力
    printf("%ld\n", calc_min_Move_Cost(R, G, B) );
    return 0;
}
