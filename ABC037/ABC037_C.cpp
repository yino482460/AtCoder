#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, K;
  cin >> N >> K;
  vector<long long> a(N, 0), S(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (i == 0)
    {
      S[i] = a[i];
    }
    else
    {
      S[i] = S[i-1] + a[i];
    }
  }

  /* 計算 */
  long long ans = 0;
  for (int i = 0; i < N-K+1; i++) {
    if (i == 0)
    {
      ans = S[K-1];
    }
    else
    {
      ans += S[i+K-1] - S[i-1];
    }
  }

  /* 出力 */
  cout << ans << endl;

  return 0;
}
