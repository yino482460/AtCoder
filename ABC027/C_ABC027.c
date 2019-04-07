#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 変数
    long long N;
    // 入力
    scanf("%lld", &N);
    // 木の深さを計算
    int depth = 0;
    for ( ; ; depth++) {
      if ( (1LL<<depth) <= N+1 && 2*(1LL<<depth)-1 >= N+1 ) {
         break;
      }
   }
    // 最善手を計算
    long long x = 1;
    int cnt = 0;
    while (1) {
        if (depth%2) {
            x = x*2; cnt ++;
            if (x >= N+1) { break; }
            x = x*2+1; cnt ++;
            if (x >= N+1) { break; }
        } else {
            x = x*2+1; cnt ++;
            if (x >= N+1) { break; }
            x = x*2; cnt ++;
            if (x >= N+1) { break; }
        }
    }
    // 出力
    // printf("cnt %d\n", cnt);
    if (cnt&1) {
        printf("Aoki\n");
    } else {
        printf("Takahashi\n");
    }
    return 0;
}
