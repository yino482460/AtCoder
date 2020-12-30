#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  long long N, ti, ai;
  vector<long long> a, t;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> ti >> ai;
    a.push_back(ai);
    t.push_back(ti);
  }

  /* 計算 */
  long long aoki, takagi, n;
  aoki = 1;
  takagi = 1;
  for (int i = 0; i < N; i++) {
    n = max((aoki+a[i]-1)/a[i], (takagi+t[i]-1)/t[i]);
    aoki = n*a[i];
    takagi = n*t[i];
  }

  /* 出力 */
  long long ans = aoki + takagi;
  cout << ans << endl;

  return 0;
}
