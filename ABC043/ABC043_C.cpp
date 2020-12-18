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

  /* 計算 */
  int ans = 1e9;
  for (int i = -100; i <= 100; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
      sum += (i-a[j])*(i-a[j]);
    }
    ans = min(ans, sum);
  }

  /* 出力 */
  cout << ans << endl;

  return 0;
}
