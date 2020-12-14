#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, tmp;
  vector<int> a;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    a.push_back(tmp);
  }
  a.push_back(0);

  /* 計算 */
  int l = 0, r = 0;
  long long ans = 0;
  while (l < N)
  {
    while (a[r] < a[r+1])
    {
      r++;
    }
    ans += (long long) r - l + 1;
    l++;
    if (l == r+1)
    {
      r++;
    }
  }

  /* 出力 */
  cout << ans << endl;

  return 0;
}
