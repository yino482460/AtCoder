#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, tmp;
  vector< pair<int, int> > a;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    a.push_back(make_pair(tmp, i+1));
  }

  /* 計算 */
  sort(a.rbegin(), a.rend());

  /* 出力 */
  for (int i = 0; i < N; i++) {
    cout << a[i].second << endl;
  }

  return 0;
}
