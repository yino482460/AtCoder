#include <stdio.h>
#define swap(a, b) (a+=b, b=a-b, a-=b)
// リスト
typedef struct list_t {
    int C;
    struct list_t *next;
} list_t;
// ソート
void quicksort (int left, int right, list_t *list) {
    int pivot = list[(left+right)/2].C;
    int i = left, j = right;
    // ソート
    while (1) {
        while (list[i].C  > pivot ) { i++; }
        while (list[j].C < pivot ) { j--; }
        if (i >= j) {
            break;
        }
        swap(list[i].C, list[j].C);
        i++; j--;
    }
    if (left < i-1) {
        quicksort(left, i-1, list);
    }
    if (j+1 < right) {
        quicksort(j+1, right, list);
    }
}
