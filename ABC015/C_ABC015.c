#include <stdio.h>
#define size 6
#define False 0
#define True 1
int T[size][size];
int cnt = 0;
int flag;
// 深さ優先探索 numQ 今の質問数
void DFS (int N, int K, int numQ, int value) {
    cnt ++;
    printf("numQ %d\n", numQ);
    if (numQ == N) {
        if (value == 0) {
            flag += True;    // バグ有り
            printf("cnt:%d flag:%d\n",cnt, flag);
            return;
        } else {
            flag += False;
            printf("cnt:%d flag:%d\n",cnt, flag);
            return;
        }
    }
    // 再帰
    for (size_t k = 0; k < K; k++) {
        value = value^T[numQ][k];
        DFS(N, K, numQ+1, value);
    }
}

int main(int argc, char const *argv[]) {
    // 変数 N 質問数
    int N, K;
    // 入力
    scanf("%d %d", &N, &K);
    for (size_t n = 0; n < N; n++) {
        for (size_t k = 0; k < K; k++) {
            scanf("%d", &T[n][k]);
        }
    }
    // 深さ優先探索
    DFS(N, K, 0, 0);
    // 出力
    if (flag == False) {
        printf("Nothing\n");
    } else {
        printf("Found\n");
    }
    return 0;
}
