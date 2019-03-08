#include <stdio.h>
#define sizeN 100002
#define sizeA 200001
#define maxLogV 30
#define Swap(a, b) (a+=b, b=a-b, a=a-b)
// 阿弥陀の到達位置を調べる
int Amida (long N, long M, long D, int A[]) {
    // D=2^iについてj番目を選ぶとどこに飛ぶかという対応表DP[i][j]
    int DP[maxLogV][sizeN];
    int toA[sizeN]; // x番目から始めて何番目に到達するか
    // 初期配置
    for (int i = 1; i <= N; i++) {
        DP[0][i] = i;
    }
    // 阿弥陀の答えを計算 D=1 (i=0)の場合
    for (long i = 0; i < M; i++) {
        Swap(DP[0][A[i]], DP[0][A[i]+1]);
    }
    // D=1について左からi番目を選ぶとどこに飛ぶか対応表
    for (size_t i = 1; i <= N; i++) {
        toA[DP[0][i]] = i;
    }
    // DPの計算
    for (int i = 0; i < maxLogV - 1; i++) {
		for (int j = 0; j < N; ++j) {
			DP[i + 1][j] = DP[i][DP[i][j]];
		}
	}



    // 出力
    for (size_t i = 1; i <= N; i++) {
        printf("%d\n", toA[i] );
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    // 変数
    long N, M, D;
    int A[sizeA];
    // 入力
    scanf("%ld %ld %ld", &N, &M, &D);
    for (int i = 0; i < M; i++) {
        scanf("%d", &A[i]);
    }
    Amida(N, M, D, A);
    return 0;
}
