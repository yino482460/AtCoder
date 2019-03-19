#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (a<b ? a:b)
// 変数
int Male, Female, P, Q, R;
// ヴァレンタイン
typedef struct valentine {
    int woman;
    int man;
    int happines;   // 幸福度
} valen_t;
// 深さ優先探索
int DFS(int female, int numOfPeople, int Happines, valen_t chocolate[]) {
    if (numOfPeople == P) {  // P人に達すれば
        Happines += chocolate[female].happines;
        return Happines;
    }

}

int main(int argc, char const *argv[]) {
    valen_t *chocolate;
    // 入力
    scanf("%d %d %d %d %d", &Male, &Female, &P, &Q, &R);
    chocolate = (valen_t *)malloc(sizeof(valen_t)*R);
    for (size_t i = 0; i < R; i++) {
        scanf("%d %d %d", &chocolate[i].woman, &chocolate[i].man, &chocolate[i].happines);
    }

    return 0;
}
