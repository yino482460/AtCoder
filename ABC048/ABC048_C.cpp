#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, x, ai;
  vector<int> a;
  cin >> N >> x;
  for (int i = 0; i < N; i++) {
    cin >> ai;
    a.push_back(ai);
  }

  /* 計算 */
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (i == 0)
    {
      if( a[i] > x ) {
        ans += (long long)(a[i] - x);
        a[i] = x;
      }
    }
    else
    {
      if (a[i-1] + a[i] > x)
      {
        ans += (long long)(a[i] - (x - a[i-1]));
        a[i] = x - a[i-1];
      }
    }
  }

  /* 出力 */
  cout << ans << endl;

  return 0;
}
