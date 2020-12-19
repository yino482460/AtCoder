#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, K, X, Y;
  cin >> N >> K >> X >> Y;

  /* 計算 */
  int ans = 0;
  if (N > K)
  {
    ans = K * X + (N - K) * Y;;
  }
  else
  {
    ans = N*X;
  }

  /* 出力 */
  cout << ans << endl;

  return 0;
}
