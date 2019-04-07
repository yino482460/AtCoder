#include <stdio.h>
#define min(a, b) (a<b ? a:b)
// 変数
int N, D, K;
// 最小移動日数の計算
void calcShortestMove (int l[], int r[], int s[], int t[]) {
    int ans[100];
    for (size_t i = 0; i < K; i++) {
        ans[i] = D;
    }
    // 貪欲法
    for (size_t i = 0; i < D; i++) {
        for (size_t j = 0; j < K; j++) {
            if (ans[j] != D) {
                continue;
            }
            if(l[i] <= s[j] && s[j] <= r[i]){
                if(l[i] <= t[j] && t[j] <= r[i]){
                    ans[j] = min(ans[j], i+1);
                }else if(s[j] < t[j]){
                    s[j] = r[i];
                }else if(t[j] < s[j]){
                    s[j] = l[i];
                }
            }
        }
    }
    for (size_t i = 0; i < K; i++) {
        printf("%d\n", ans[i]);
    }
}

// メイン
int main(int argc, char const *argv[]) {
    // 入力
    scanf("%d %d %d", &N, &D, &K);
    int L[D], R[D];
    int S[K], T[K];
    int l, r;
    for (size_t i = 0; i < D; i++) {
        scanf("%d %d", &l, &r);
        l--; r--;
        L[i] = l; R[i] = r;
    }
    int s, t;
    for (size_t i = 0; i < K; i++) {
        scanf("%d %d", &s, &t);
        s--; t--;
        S[i] = s; T[i] = t;
    }
    // 出力
    calcShortestMove(L, R, S, T);
    return 0;
}
