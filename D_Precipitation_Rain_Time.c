#include <stdio.h>
#include <string.h>

#define N_max 30001

//時刻の切り下げ
int Time_to_minutes_Round_dowm (int Time) {
    Time = ((Time/100)*60 + Time%100)/5*5;
    return Time;
}
//時刻の切り上げ
int Time_to_minutes_Round_up (int Time) {
    Time = ((Time/100)*60 + Time%100 + 4)/5*5;;
    return Time;
}

//経過分を時刻に変換する関数
int minutes_to_Time (int minutes) {
    int Time;
    Time = (minutes/60)*100 + minutes%60;
    return Time;
}
// 時刻を経過分に変換する関数
int Time_to_minutes (int Time) {
    int minutes;
    minutes = (Time/100)*60 + Time%100;
    return minutes;
}

// imos法 配列 24x12 = 288
int imos[24][12] = {0};
// imos法 実装
void Imos(int startTime, int endTime) {
    int S_hour, S_minutes;
    int E_hour, E_minutes;
    // 時間と分の取得
    S_hour = startTime/100; S_minutes = (startTime%100)%12;
    E_hour = endTime/100; E_minutes = (endTime%100)%12;
    //フラグの挿入
    imos[S_hour][S_minutes] = 1;    //始点
    imos[E_hour][E_minutes+1] = -1;     //終点の一つ先
}


int main(int argc, char const *argv[]) {
    //入力
    int N, i;
    int S[N_max], E[N_max];
    scanf("%d", &N );
    //時刻の読み込み
    for (i = 0; i < N; i++) {
        scanf("%d-%d", &S[i], &E[i] );
        S[i] = Time_to_minutes_Round_dowm(S[i]);
        E[i] = Time_to_minutes_Round_up(E[i]);
        S[i] = minutes_to_Time(S[i]);
        E[i] = minutes_to_Time(E[i]);
    }


    //確認用
    for ( i = 0; i < N; i++) {
        printf("%04d %04d\n", S[i], E[i] );
    }
    return 0;
}
