#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int a, b, c;
  cin >> a >> b >> c;

  /* 計算 */
  bool flag = false;
  if (a == (b+c) || b ==  (a+c) || c == (a+b))
  {
    flag = true;
  }

  /* 出力 */
  if (flag)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}
