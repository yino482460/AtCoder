#include <stdio.h>
#include <string.h>
// 変数
int N, A, B;
// 移動距離の計算
int Dist (int d) {
    int dist = 0;
    if (d < A) {
        dist = A;
    } else if (B < d) {
        dist = B;
    } else {
        dist = d;
    }
    return dist;
}

// メイン
int main(int argc, char const *argv[]) {
    scanf("%d %d %d", &N, &A, &B);
    char s[6];
    int d;
    int dist = 0;
    for (size_t i = 0; i < N; i++) {
        scanf("%s", s);
        scanf("%d", &d);
        char e[] = "East";
        int flag = 0;
        if (strcmp(s, e)!=0) {  // 西の時は負
            flag = -1;
        }
        if (flag == -1) {
            dist -= Dist(d);
        } else {
            dist += Dist(d);
        }
    }
    // 出力
    if (dist > 0) {
        printf("East %d\n", dist);
    } else if (dist < 0) {
        printf("West %d\n", -dist);
    } else {
        printf("0\n");
    }
    return 0;
}
