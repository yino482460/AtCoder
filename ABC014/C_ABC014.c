#include <stdio.h>
#define size 1000005
#define max(a, b) (a>b ? a:b)
// Imos法
int retCostmer(int n, int a[], int b[]) {
    int costmers = 0;
    int Imos[size] = {0};
    // 始点と終点を格納
    for (size_t i = 0; i < n; i++) {
        Imos[a[i]] ++;
        Imos[b[i]+1] --;
    }
    // 被覆
    costmers = Imos[0];
    for (int i = 1; i < size; i++) {
        Imos[i] += Imos[i-1];
        costmers = max(costmers, Imos[i]);
    }
    return costmers;
}

int main(int argc, char const *argv[]) {
    // 変数
    int n;
    int a[size], b[size];
    // 入力
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    // 出力
    int costmers = retCostmer(n, a, b);
    printf("%d\n", costmers);
    return 0;
}
