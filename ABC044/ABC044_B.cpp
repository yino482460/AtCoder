#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  string w;
  cin >> w;

  /* 判定 */
  bool flag = true;
  char cha = 'a';
  for (int i = 0; i <= 25; i++) {
    int cnt = 0;
    for (int j = 0; j < w.size(); j++) {
      if (cha == w[j])
      {
        cnt++;
      }
    }
    if (cnt%2 == 1) // 判定
    {
      flag = false;
      break;
    }
    cha += 1;
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
