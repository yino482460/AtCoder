#include <stdio.h>
#include <string.h>
#define N_max 51
#define Q_max (N_max*N_max)
int Taste[N_max][N_max];
int Taste_sum[N_max][N_max];
// 変数
int N;
int Q, P[Q_max];    // 店員の人数

// ある大きさの長方形の美味しさの合計値の計算
int sum_right (int i, int j) {
    if (i>N || j>N) {
        return 0;
    } else if (i==N && j==N) {
        Taste_sum[N][N] = Taste[N][N];
        return Taste_sum[N][N];
    } else if (Taste_sum[i][j] != 0) {  // メモ化
        return Taste_sum[i][j];
    } else {
        Taste_sum[i][j] = sum_right(i+1, j) + sum_right(i, j+1);
        Taste_sum[i][j] -=  sum_right(i+1, j+1);
        Taste_sum[i][j] += Taste[i][j];
    }
    return Taste_sum[i][j];
}
// 右下までの各大きさの長方形を計算
void calc_all_sum (int N) {
    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            sum_right(i, j);
        }
    }
}

int main(int argc, char const *argv[]) {
    // 美味しさの入力
    scanf("%d", &N );
    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            scanf("%d", &Taste[i][j] );
        }
    }
    // 店員の人数t、焼ける個数を入力
    scanf("%d", &Q );
    for (size_t i = 1; i <= Q; i++) {
        scanf("%d", &P[i] );
    }
    // Taste_sumを0で初期化
    memset(Taste_sum, 0, sizeof(Taste_sum));
    calc_all_sum(N);
    // 右下までの和
    for (size_t i = 0; i <= N; i++) {
        for (size_t j = 0; j <= N; j++) {
            printf("%2d ", Taste_sum[i][j]);
        }
        printf("\n");
    }


    return 0;
}
