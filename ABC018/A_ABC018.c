#include <stdio.h>
#define swap(a, b) (a+=b, b=a-b, a-=b)
// ソート
void sort (int num[], int left, int right) {
    int pivot = num[(left+right)/2];
    int i = left, j = right;
    while (1) { // 無限ループ
        while (num[i] > pivot) { i ++; }
        while (num[j] < pivot) { j --; }
        if (i >= j) {
            break;
        }
        swap(num[i], num[j]);
        i++; j--;
    }
    if (left < i-1) {
        sort(num, left, i-1);
    }
    if (j+1 < right) {
        sort(num, j+1, right);
    }
}

int main(int argc, char const *argv[]) {
    // 変数
    int num[3];
    // 入力
    for (size_t i = 0; i < 3; i++) {
        scanf("%d", &num[i]);
    }
    // ソート
    sort(num, 0, 2);
    // 出力
    for (size_t i = 0; i < 3; i++) {
        printf("%d\n", num[i]);
    }
    return 0;
}
