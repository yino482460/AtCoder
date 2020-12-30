#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, K;
  cin >> N >> K;

  /* 計算 */
  long long ans = K;
  for (int i = 1; i < N; i++) {
    ans *= K-1;
  }

  /* 出力 */
  cout << ans << endl;

  return 0;
}
