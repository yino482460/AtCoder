#include <stdio.h>
#include <string.h>

// 風向きの配列
char Dir[18][4] = {
    "N", "NNE", "NE", "ENE",
    "E", "ESE", "SE", "SSE",
    "S", "SSW", "SW", "WSW",
    "W", "WNW", "NW", "NNW",
};

// ビューフォート風力段階
double Beaufort[13] = {
    0.25, 1.55, 3.35, 5.45, 7.95, 10.75, 13.85,
    17.15, 20.75, 24.45, 28.45, 32.65, 32.7
};

//風程
int WP[13] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
};
//誤差補正量
double gosa = 0.00001;

//風程を計算する関数
int Futei(double Dis) {
    int count = sizeof Beaufort / sizeof Beaufort[0];
    int WindPower = 0;
    Dis = Dis/60 + gosa;
    if (Dis >= Beaufort[12]) {
        WindPower = WP[12];
        return WindPower;
    } else {
        for (size_t i = 0; i < count ; i++) {
            if (Dis < Beaufort[i]) {
                WindPower = WP[i];
                break;
            }
        }
    }
    return WindPower;
}


int main(int argc, char const *argv[]) {
    //変数  風の角度 風速
    double Deg, Dis;
    //入力
    scanf("%lf%lf", &Deg, &Dis );

    // 風の強さの分類
    int WindPower = Futei(Dis);
    //風向きの方角の計算 (余りで分類)
    int deg;
    deg = ((int) ((Deg*10+1125)/2250))%16;
    char direction[4];
    //風速が0の時の処理
    if (WindPower == 0) {
        strncpy(direction, "C", 4);
    } else {
        strncpy(direction, Dir[deg], 4);
    }

    //出力
    printf("%s %d\n", direction, WindPower);
    return 0;
}
