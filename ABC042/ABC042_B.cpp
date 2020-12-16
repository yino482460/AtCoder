#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, L;
  string s;
  vector<string> S;
  cin >> N >> L;
  for (int i = 0; i < N; i++) {
    cin >> s;
    S.push_back(s);
  }

  /* sort */
  sort(S.begin(), S.end());

  /* 出力 */
  for (int i = 0; i < N; i++) {
    cout << S[i];
  }
  cout << endl;

  return 0;
}
