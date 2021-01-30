#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  string S;
  cin >> S;
  reverse(S.begin(), S.end());

  /* 判定 */
  string T[4] = {"dream", "dreamer", "erase", "eraser"};
  for (int i = 0; i < 4; i++) {
    reverse(T[i].begin(), T[i].end());
  }

  bool flag;
  for (int i = 0; i < S.size();) {
    flag = false;
    for (int j = 0; j < 4; j++) {
      if (T[j] == S.substr(i, T[j].size()))
      {
        i += T[j].size();
        flag = true;
        break;
      }
    }
    if (flag == false)
    {
      break;
    }
  }

  /* 出力 */
  if (flag)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }

  return 0;
}
