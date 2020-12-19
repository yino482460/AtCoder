#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, A, tmp, vmax = 0;
  vector<int> x, y;
  cin >> N >> A;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    x.push_back(tmp);
    vmax = max(tmp, vmax);
    y.push_back(tmp-A);
  }

  /* 計算 */
  int X = max(vmax, A);
  long long dp[N+1][2*N*X+1];

  // 初期化
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= 2*N*X; j++) {
      dp[i][j] = 0;
    }
  }

  dp[0][N*X] = 1;

  for (int j = 0; j <= N ; j++) {
    for (int t = 0; t <= 2*N*X; t++) {
      if (j >= 1 && t-y[j] < 0 || t-y[j] > 2*N*X)
      {
        dp[j][t] = dp[j-1][t];
      } else if (j >= 1 && 0 <= t-y[j] && t-y[j] <= 2*N*X) {
        dp[j][t] = dp[j-1][t] + dp[j-1][t-y[j]];
      } else {
        dp[j][t] = 0;
      }
    }
  }

  /* 出力 */
  cout << dp[N][N*X]-1 << endl;

  return 0;
}
