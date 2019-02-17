#include <stdio.h>
#define R_max 4001
int Rate[R_max] = {0};
// 交換
void Swap (int x[],int a, int b) {
    int tmp;
    tmp = x[a]; x[a] = x[b]; x[b] = tmp;
}
// 降順に並び替え
void QuickSort( int Array[], int left, int right ) {
    int i, j;
    int pivot;
    i = left; j = right;
    pivot = Array[ (left+right)/2 ];

    // 無限ループ
    while (1) {
        while (Array[i] > pivot) {  i ++; } // pivotより小さい値が見つかるまで
        while (pivot > Array[j]) { j --; }  // pivotより大きい値が見つかるまで
        if (i >= j) {
            break;  // i >= jならば無限ループから脱出
        }
        Swap(Array, i, j);
        i ++; j--;  // 次のデータ
        }
    if (left < i-1) {   // 左に二つ以上の要素があればソート
        QuickSort( Array, left, i-1 );
    }
    if (j+1 < right) {
        QuickSort( Array, j+1, right );
    }
}


int main(int argc, char const *argv[]) {
    // 変数
    int N, K;
    scanf("%d %d", &N, &K );
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &Rate[i] );
    }
    // ソート
    QuickSort( Rate, 0, N-1 );
    for (size_t i = 0; i < N; i++) {
        printf("%d ", Rate[i] );
    }
    printf("\n");


    return 0;
}
