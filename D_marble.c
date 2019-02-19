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
// 箱の初期位置
int RGB[3] = {-100, 0, 100};
// 現在地とマーブルの残り個数から移動に要する手数を計算
int calc_Move (int look, int marbles) {
    if (marbles < R ) { // 残り個数がR個以下のとき
        return abs(look - RGB[0]);
    } else if (marbles < R+G) {
        return abs(look - RGB[1]);
    } else {
        return abs(look - RGB[2]);
    }
}
// 最小移動数を計算する
long DFS (int look, int marbles) {
    if (dp[look+1000][marbles] != -1) { return dp[look+1000][marbles];}
    if (look > 999) { return Infinity;}
    if (marbles == sum) {return 0;}
    long calc1, calc2;
    calc1 = DFS(look+1, marbles+1) + calc_Move(look, marbles);
    calc2 = DFS(look+1, marbles);
    dp[look+1000][marbles]=(calc1 > calc2 ? calc2 : calc1);
    return dp[look+1000][marbles];
}


int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d %d %d", &R, &G, &B);
    sum = R+G+B;
    // dpに初期値を設定
    memset(dp,-1,sizeof(dp));
    // 出力
    printf("%ld\n", DFS(-1000, 0) );
    return 0;
}
