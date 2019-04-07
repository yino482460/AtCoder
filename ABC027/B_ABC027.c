#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    int N;
    scanf("%d", &N);
    int a[N], memo[N], sum = 0;
    // 入力
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        memo[i] = sum;
    }
    // 橋の本数の計算
    // 例外処理
    if (sum%N != 0) {
        printf("-1\n");
        return 0;
    }
    // 計算
    int bridges = 0;
    int people = sum/N;
    for (int i = 0; i < N - 1; ++i){
        int l = memo[i], r = sum - memo[i]; //橋を挟んで左側と右側に必要な人の数
        if(l == people * (i + 1) && r == people * (N - (i + 1))) { continue;
        }
        bridges++;
    }
    // 出力
    printf("%d\n", bridges);
    return 0;
}
