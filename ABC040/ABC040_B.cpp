#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int n;
  cin >> n;

  /* 計算 */
  int ans = pow(10, 7);

  for (int h = 1; h <= n; h++) {
    for (int w = 1; w <= n/h; w++) {
      int remain = n - h*w;
      ans = min(ans, remain+abs(h-w));
    }
  }

  /* 出力 */
  cout << ans << endl;

  return 0;
}
