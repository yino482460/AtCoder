#include <stdio.h>
#define gold 1
#define Machine -1
#define Max 1000001
int Board[Max][Max];
// 金塊と装置を盤面に配置
void setGolds (int W, int H, int machine[][]) {
    int No = 0;
    for (size_t i = 1; i <= H; i++) {
        for (size_t j = 1; j <= W; j++) {
            if (machine[No][0]==W && machine[No][1] == H) {
                Board[i][j] = Machine;
                No++;
            } else {
                Board[i][j] = gold;
            }
        }
    }

}

int main(int argc, char const *argv[]) {
    // 変数
    int W, H, N;
    scanf("%d %d %d", &W, &H, &N );
    int machine[N+1][2];    // 回収装置の座標
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j <= 1; j++) {
            scanf("%d", &machine[i][j] );
        }
    }

    return 0;
}
