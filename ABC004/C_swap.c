#include <stdio.h>
#define Num_of_Cards 6
#define mod 5
#define swap(a, b) (a+=b, b=a-b, a-=b)
int Cards[6] = {1, 2, 3, 4, 5, 6};

int main(int argc, char const *argv[]) {
    // 入力
    long N;
    // 読み込み
    scanf("%ld", &N );
    // 計算の効率化
    N = N%(Num_of_Cards*mod);
    for (int i = 0; i < N; i++) {
        swap( Cards[i%5], Cards[i%5+1] );
    }
    // 出力
    for (int i = 0; i < Num_of_Cards; i++) {
        printf("%d", Cards[i] );
    }
    printf("\n");
    return 0;
}
