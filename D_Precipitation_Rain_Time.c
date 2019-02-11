#include <stdio.h>
#include <string.h>

#define N_max 30001

//時刻の切り下げ
int Round_down_Time (int Time) {
    Time = ((Time/100)*60 + Time%100)/5*5;
    return Time;
}
//時刻の切り上げ
int Round_up_Time (int Time) {
    Time = ((Time/100)*60 + Time%100 + 4)/5*5;;
    return Time;
}

//経過分を時刻に変換する関数
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
        //時刻の切り下げ、切り上げ
        S[i] = Round_down_Time(S[i]);
        E[i] = Round_up_Time(E[i]);
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
