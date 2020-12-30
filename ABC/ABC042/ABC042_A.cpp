#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int A[3];
  for (int i = 0; i < 3; i++) {
    cin >> A[i];
  }

  /* 判定 */
  bool flg = true;
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    if (A[i] == 5 || A[i] == 7)
    {
      sum += A[i];
      if (sum > 17)
      {
        flg = false;
      }
    } else
    {
      flg = false;
      break;
    }
  }

  /* 出力 */
  if (flg)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }

  return 0;
}
