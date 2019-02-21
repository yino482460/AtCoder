#include <stdio.h>
#include <string.h>
#define max(a,b) (a>b ? a:b)
#define N_max 52
#define Q_max (N_max*N_max)
int Taste[N_max][N_max];
int Taste_right[N_max][N_max];
int Taste_any[N_max][N_max][N_max][N_max];
int Area_max[Q_max] = {0};
// 変数
int N;
int Q, P[Q_max];    // 店員の人数

// ある大きさの長方形の美味しさの合計値の計算
int sum_right (int i, int j) {
    if (i>N || j>N) {
        return 0;
    } else if (i==N && j==N) {
        Taste_right[N][N] = Taste[N][N];
        return Taste_right[N][N];
    } else if (Taste_right[i][j] != 0) {  // メモ化
        return Taste_right[i][j];
    } else {
        Taste_right[i][j] = sum_right(i+1, j) + sum_right(i, j+1);
        Taste_right[i][j] -=  sum_right(i+1, j+1);
        Taste_right[i][j] += Taste[i][j];
    }
    return Taste_right[i][j];
}
// 右下までの各大きさの長方形を計算
void calc_all_rightRectanle (int N) {
    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            sum_right(i, j);
        }
    }
}
// 任意の長方形の領域での美味しさを計算
int calc_any_Rectangle (int i, int j, int v, int h) {
    int any_taste_sum = 0;
    any_taste_sum = Taste_right[i][j] - Taste_right[i+v][j] - Taste_right[i][j+h] + Taste_right[i+v][j+h];
    Taste_any[i][j][v][h] = any_taste_sum;

    return Taste_any[i][j][v][h];
}
// 全ての任意の長方形での美味しさの合計を計算
void calc_all_Rectangle (int N) {
    calc_all_rightRectanle(N);
    int area = 0;
    // ループ本体
    for (int i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            for (size_t v = 1; v <= N-i+1; v++) {
                for (size_t h = 1; h <= N-j+1; h++) {
                    area = v*h;
                    Area_max[area] = max(Area_max[area], calc_any_Rectangle(i, j, v, h));
                }
            }
        }
    }

}
// 全ての面積で最大値を再計算
void recalc_total_Taste (long all_rectangle) {
    for (size_t i = 1; i <= all_rectangle; i++) {
        Area_max[i] = max(Area_max[i-1], Area_max[i]);
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
    // Taste_rightを0で初期化
    memset(Taste_right, 0, sizeof(Taste_right));
    // 計算
    calc_all_Rectangle(N);
    // 順位の計算
    long all_rectangle = N*N;
    recalc_total_Taste(all_rectangle);
    // 出力
    for (size_t i = 1; i <= Q; i++) {
        printf("%d\n", Area_max[P[i]] );
    }
    return 0;
}
