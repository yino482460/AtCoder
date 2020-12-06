#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N;
  cin >> N;
  long long a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  /* 計算 */
  long long dp[N];
  dp[0] = 0;
  dp[1] = abs(a[1] - a[0]);
  dp[2] = min(abs(a[2]-a[0]), dp[1]+abs(a[2]-a[0]));
  // 動的計画法
  if (N > 3)
  {
    for (int i = 3; i < N; i++)
    {
      dp[i] = min(dp[i-1]+abs(a[i]-a[i-1]), dp[i-2]+abs(a[i]-a[i-2]));
    }
  }

  /* 出力 */
  cout << dp[N-1] << endl;

  return 0;
}
