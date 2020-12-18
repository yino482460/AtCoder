#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  string s;
  cin >> s;

  /* 判定 */
  int l = 0, r = 0;
  bool flag = false;
  for (int i = 0; i < s.size(); i++) {
    if (i+1 < s.size() && s[i] == s[i+1])
    {
      l = i;
      r = i+1;
      flag = true;
      break;
    }
    else if (i+2 < s.size() && s[i] == s[i+2]) {
      l = i;
      r = i+2;
      flag = true;
      break;
    }
  }

  /* 出力 */
  if (flag) {
    cout << l+1 << " " << r+1 << endl;
  }
  else {
    cout << -1 << " " << -1 << endl;
  }

  return 0;
}
