#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, M;
  cin >> N >> M;
  int x[M], y[M];
  for (int i = 0; i < M; i++) {
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }

  /* 計算 */
  vector<long long> dp(1LL<< N, 0); // 2^N個の要素を持つ配列
  dp[0] = 1;  // 頂点数なし

  for (long long bit = 0; bit < 1LL<<N; bit++) {
    vector<int> cnt(N, 0);
    for (int i = 0; i < M; i++)
    {
      if (bit & (1LL << x[i]))  // 有向グラフの構築
      {
        if (bit & (1LL << y[i]))
        {
          cnt[x[i]]++;
        }
      }
    }
    for (int i = 0; i < N; i++)
    {
      if (bit & (1LL << i))
      {
        if (cnt[i] == 0)
          dp[bit] += dp[bit & ~(1LL << i)];
      }
    }
  }

  // 出力
  cout << dp[(1LL<<N) - 1] << endl;
  return 0;
}
