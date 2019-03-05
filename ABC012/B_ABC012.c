#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    int time;
    // 入力
    scanf("%d", &time);
    // 計算
    int hour, minutes, sec;
    hour = time/3600;
    time = time%3600;
    minutes = time/60;
    time = time%60;
    sec = time;
    // 出力
    printf("%02d:%02d:%02d\n", hour, minutes, sec);
    return 0;
}
