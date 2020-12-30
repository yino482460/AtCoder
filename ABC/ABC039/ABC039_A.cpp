#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int A[3];
  for (int i = 0; i < 3; i++) {
    cin >> A[i];
  }

  /* 出力 */
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    if (i<2)
    {
      ans += A[i] * A[i + 1];
    }
    else
    {
      ans += A[0]*A[2];
    }
  }
  ans = 2*ans;
  cout << ans << endl;

  return 0;
}
