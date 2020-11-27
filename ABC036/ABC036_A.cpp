#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int A, B;
  cin >> A >> B;

  /* 計算 */
  if (B%A == 0)
  {
    cout << B/A << endl;
  }
  else
  {
    cout << B/A+1 << endl;
  }

  return 0;
}
