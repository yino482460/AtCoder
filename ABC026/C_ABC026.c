#include <stdio.h>
#include <stdlib.h>
#define Nmax 21
#define max(a, b) (a>b ? a:b)
#define min(a, b) (a<b ? a:b)
// リスト
typedef struct list_t {
    int sub;    // 部下
    int size;   // 何人の部下を持っているか
    struct list_t *head;    // リストの先頭
    struct list_t *previous;    // 自分の一つ前
} list_t;
// リストの初期化
void  InitList (int N, list_t list[]) {
    for (size_t i = 0; i < N; i++) {
        list[i].size = 0;
        list[i].head = &list[i];
        list[i].previous = NULL;
    }
}
// リストに追加
void addList (int Sub, list_t a) {
    list_t *new_l;
    new_l = (list_t *)malloc(sizeof(list_t));   // 新規メモリの確保
    new_l -> size = (a.head) -> size + 1;
    new_l -> sub = Sub;
    new_l -> previous = a.head;
    a.head = new_l;
}
// 部下の情報をリスト化
void  makeList (list_t *Sub, int N, int B[]) {
    InitList(N, Sub);
    for (int i = 1; i < N; i++) {
        addList(i, Sub[B[i]]);
    }
}
// 給料を計算
void calcSalary (int N, int B[]) {
    list_t *Sub;
    Sub = (list_t *)malloc(sizeof(list_t)*N);
    // リスト化
    makeList(Sub, N, B);
    // デバッグ
    for (int i = 0; i < N; i++) {
        printf("Sub[%d].size:%d\n", i, (Sub[i].head) -> size);
    }
    // 逆順で給料を計算
    int P[N], minP[N], maxP[N];
    int i = N-1;
    list_t *buf = Sub[i].head;
    for (i = N-1; i >= 0; i--) {
        if (buf -> size == 0) {
            P[i] = 1;
            continue;
        }
        maxP[i] = 0; minP[i] = (int)1e9;
        while ( (buf -> previous) != '\0' ) {
            int j = buf -> sub;
            maxP[i] = max(maxP[i], P[j]);
            minP[i] = min(minP[i], P[j]);
            buf = (buf -> previous);
        }
        P[i] = maxP[i]+minP[i]+1;
    }
    // 出力
    printf("%d\n", P[0]);
    // メモリ解放
    free(Sub);
}


// メイン
int main(int argc, char const *argv[]) {
    // 変数
    int N;
    // 入力
    int B[Nmax] = {0};
    scanf("%d", &N);
    for (size_t i = 1; i < N; i++) {
        scanf("%d", &B[i]);
        B[i] --;
    }
    // 出力
    calcSalary(N, B);
    return 0;
}
