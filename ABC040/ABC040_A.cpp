#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int n, x;
  cin >> n >> x;

  /* 計算 */
  n--; x--;
  int ans = min(x, n-x);

  /* 出力 */
  cout << ans << endl;
  return 0;
}
