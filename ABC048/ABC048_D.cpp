#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  string s;
  cin >> s;

  /* 計算 */
  int strlen = s.size();
  bool flag = false;
  if (strlen%2 == 0 ^ s[0] == s[strlen-1])
  {
    flag = true;
  }

  /* 出力 */
  if (flag)
  {
    cout << "Second" << endl;
  }
  else
  {
    cout << "First" << endl;
  }

  return 0;
}
