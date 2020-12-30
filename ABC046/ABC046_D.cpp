#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  string s;
  cin >> s;   //g or p

  /* 計算 */
  int N = s.size();
  int P = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'p') {
      P++;
    }
  }
  int ans = N/2 - P;

  /* 出力 */
  cout << ans << endl;

  return 0;
}
