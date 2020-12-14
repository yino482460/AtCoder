#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1e9+7;

int main(int argc, char const *argv[])
{
  /* 入力 */
  long long A[3];
  for (int i = 0; i < 3; i++) {
    cin >> A[i];
  }

  /* 出力 */
  long long ans = 1;
  for (int i = 0; i < 3; i++) {
    ans *= A[i];
    ans = ans%MOD;
  }
  cout << ans%MOD << endl;

  return 0;
}
