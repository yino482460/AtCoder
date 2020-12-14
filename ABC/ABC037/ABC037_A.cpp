#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int A, B, C;
  cin >> A >> B >> C;

  /* 計算 */
  int ans, tmp;;
  if (A < B)
  {
    ans = C/A;
    tmp = C - ans*A;
    ans += tmp/B;
  }
  else
  {
    ans = C/B;
    tmp = C - ans*B;
    ans += tmp/A;
  }

  /* 出力 */
  cout << ans << endl;

  return 0;
}
