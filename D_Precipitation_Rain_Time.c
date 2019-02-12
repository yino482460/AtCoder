#include <stdio.h>
#include <string.h>

#define N_max 30002

//時刻の切り下げ
int Time_to_minutes_Round_dowm (int startTime) {
    int minutes;
    minutes = ((startTime/100)*60 + startTime%100)/5*5;
    return minutes;
}
//時刻の切り上げ
int Time_to_minutes_Round_up (int endTime) {
    int minutes;
    minutes = ((endTime/100)*60 + endTime%100 + 4)/5*5;
    int limit = 24*60;
    if (minutes >= limit) {
        minutes = limit;
    }
    return minutes;
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

// imos法 配列 24x60
#define H 25
#define M 60
int imos[H][M] = {0};
//雨が降っている期間
int start[300] = {0}, end[300] = {0};

// imos法 実装 Nはデータの数
void Imos(int N, int startTime[], int endTime[]) {
    int S_hour, S_minutes;
    int E_hour, E_minutes;
    int i, j;
    // 符号化処理
    for ( i = 0; i < N; i++) {
        // 開始
        S_hour = startTime[i]/100;
        S_minutes = startTime[i]%100;
        // 終了
        E_hour = endTime[i]/100;
        E_minutes = endTime[i]%100;
        //フラグの挿入　2019 02 12 12:40 修正
        imos[S_hour][S_minutes] ++;    //始点
        imos[E_hour][E_minutes+1] --;     //終点の一つ先
    }
    printf("1:imos[0][0] %d\n", imos[0][0]);
    //フラグの和の計算
    for ( i = 0; i < H; i++) {
        for ( j = 0; j < M; j++) {
            if ( (i==0) && (j==0) ) {
                imos[0][1] += imos[0][0];
                j++;
                continue;
            } else {
                imos[i][j] += imos[i][j-1];
            }
        }
    }
    printf("2:imos[0][0] %d\n", imos[0][0]);


    // 降り始めと雨上がりを時刻に換算
    int count = -1;
    for ( i = 0; i < H; i++) {
        for ( j = 0; j < M; j++) {
            // imos[0][0]の処理
            if ( (i==0) && (j==0) ) {
                count ++;
                start[count] = 0;
                printf("3:imos[0][0] %d\n", imos[0][0]);
                // imos[0][0]は次に飛ぶ
                j++;
                continue;
            }
            //降り始めの時刻
            if ( (imos[i][j-1]==0) && (imos[i][j]>=1)  ) {
                count ++;
                start[count] = i*100 + j;
            //雨上がりの時刻
            } else if ( (imos[i][j]>=1) && (imos[i][j+1]==0) ) {
                end[count] = i*100 + j;
            } else {
                // 何もしない
            }
        }
    }
}


// メイン
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
    //時刻データの整理
    Imos(N, S, E);
    // 出力
    printf("start[0] %d, end[0] %d\n", start[0], end[0]);
    for ( i = 0; i < N; i++) {
        if (end[i] > 0) {
            printf("%04d-%04d\n", start[i], end[i] );
        }
    }
    return 0;
}
