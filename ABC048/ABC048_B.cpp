#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  long long a, b, x;
  cin >> a >> b >> x;

  /* 計算 */
  long long ans;
  if (a%x == 0)
  {
    ans = b/x - a/x + 1;
  }
  else
  {
    ans = b/x - a/x;
  }

  /* 出力 */
  cout << ans << endl;

  return 0;
}
