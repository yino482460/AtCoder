#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define swap(a, b) (a+=b, b=a-b, a-=b)
// リスト
typedef struct list_t {
    int C;
    struct list_t *next;
} list_t;
// 記憶領域の取得
struct list_t* listmalloc(void) {
    return (list_t*)malloc(sizeof(list_t));
}
// リストに追加
void add(int cnt, list_t *new, list_t *old) {
    old -> next = new;
    new -> C = cnt;
    old = new;
}
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
// 幸福度の計算
void Happiness (char S[]) {
    int length = strlen(S), cnt = 0, size = 0;
    list_t *head, *p, *old;
    head = listmalloc();
    old = head;
    for (size_t i = 0; i < length; i++) {
        if (S[i] == '+') {
            cnt++; size++;
            p = listmalloc();
            add(cnt, p, old);
        } else if (S[i] == '-') {
            cnt --; size++;
            p = listmalloc();
            add(cnt, p, old);
        }
    }
    // ソート
    quicksort(0, size, p);

}

// メイン
int main(int argc, char const *argv[]) {
    int sizeS = pow(10, 5) + 1;
    // 変数
    char S[sizeS];
    scanf("%s", S);

    return 0;
}
