#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  string s;
  cin >> s;

  /* 処理 */
  vector<char> c;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'B')
    {
      if (c.size() == 0)
      {
        continue;
      }
      c.pop_back();
    } else
    {
      c.push_back(s[i]);
    }
  }

  /* 出力 */
  for (int i = 0; i < c.size(); i++) {
    cout << c[i];
  }
  cout << endl;

  return 0;
}
