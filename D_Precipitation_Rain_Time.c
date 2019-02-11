#include <stdio.h>
#include <string.h>

#define N_max 30001

int minutes_to_Time (int Time) {
    Time = (Time/60)*100 + Time%60;
    return Time;
}

int main(int argc, char const *argv[]) {
    //入力
    int N, i;
    int S[N_max], E[N_max];
    scanf("%d", &N );
    //時刻の読み込み
    for (i = 0; i < N; i++) {
        scanf("%d-%d", &S[i], &E[i] );
        //時刻を0:00からの経過分に換算
        S[i] = ((S[i]/100)*60 + S[i]%100)/5*5;
        E[i] = ((E[i]/100)*60 + S[i]%100 + 4)/5*5;
        //換算した分を時刻に変換
        S[i] = minutes_to_Time(S[i]);
        E[i] = minutes_to_Time(E[i]);
    }


    //確認用
    for ( i = 0; i < N; i++) {
        printf("%04d %04d\n", S[i], E[i] );
    }
    return 0;
}
