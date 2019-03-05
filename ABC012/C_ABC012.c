#include <stdio.h>
// 抜けた候補の探索
void Search (int N) {
    int Sum = 0;
    for (size_t i = 1; i <= 9; i++) {
        for (size_t j = 1; j <= 9; j++) {
            Sum += i*j;
        }
    }
    int dif = Sum - N;
    int dan = 1;
    while (dan <= 9) {
        if (dif%dan == 0 && dif/dan<=9) {
            printf("%d x %d\n", dan, dif/dan );
        }
        dan ++;
    }
}

int main(int argc, char const *argv[]) {
    // 変数
    int N;
    // 入力
    scanf("%d", &N);
    // 出力
    Search(N);
    return 0;
}
