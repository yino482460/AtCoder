#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  string S;
  cin >> S;

  /* 判定 */
  int a = S.length();
  if (S[a-1] == 'T')
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }

  return 0;
}
