#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
    // 変数
    int N, cnt = 0, a[10] = {0};
    // 入力
    scanf("%d", &N);
    // 計算
    for (int i = 0; i <= 3; i++) {
        //printf("i %d\n", i);
        if (((N>>i) & 1) == 1) {
            a[cnt] = pow(2, i);
            N = N-a[cnt];
            //printf("N %d\n", N);
            cnt++;
        }
        if (i==3) {
            break;
        }
    }
    printf("%d\n", cnt);
    int i = 0;
    while (a[i] != 0) {
        printf("%d\n", a[i]);
        i++;
    }
    return 0;
}
