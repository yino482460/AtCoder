#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  string S;
  cin >> S;

  /* 計算 */
  int section = 1;
  for (int i = 0; i < S.size()-1; i++) {
    if (S[i] != S[i+1])
    {
      section++;
    }
  }

  /* 出力 */
  cout << section-1 << endl;

  return 0;
}
