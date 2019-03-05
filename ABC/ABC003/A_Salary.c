#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 入力
    int N;
    int Salary = 0;
    // 読み込み
    scanf("%d", &N );
    // 計算
    for (int i = 1; i <= N; i++) {
        Salary += 10000*i;
    }
    Salary = Salary/N;
    // 出力
    printf("%d\n", Salary );
    return 0;
}
