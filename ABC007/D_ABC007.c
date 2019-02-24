#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define Max_digit 18
// 桁DP
long Rec (char num[], int k, bool tight) {
    // 答え
    if (k == strlen(num)) { // 終了条件
        return 1;
    }
    // k桁目の数字を取り出す
    int x = num[k] - '0';
    // 上位の桁が tightなら x までしか動けない
    int r = (tight ? x:9);
    // 答え
    long response = 0;
    // tight = Trueなら0~xまで、Falseなら0~9まで遷移できる
    for (size_t i = 0; i <= r; i++) {
        response += Rec(num, k+1, (tight && i==r) );
    }
    return response;
}

int main(int argc, char const *argv[]) {
    // 変数
    char A[Max_digit+1], B[Max_digit+1];
    // 入力
    scanf("%s %s", A, B );
    // 確認
    printf("A, %s res(A):%ld\n", A, Rec(A, 0, true) );
    printf("B, %s res(B):%ld\n", B, Rec(B, 0, true) );
    return 0;
}
