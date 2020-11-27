#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, tmp;
  vector<int> a, b;
  map<int, int> mp;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    a.push_back(tmp);
    b.push_back(tmp);
  }

  /* 計算 */
  sort(a.begin(), a.end());
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (mp[a[i]] == 0)
    {
      count++;
      mp[a[i]] = count;
    }
  }
  cout << "map" << endl;
  for (int i = 0; i < N; i++) {
    cout << mp[i] << endl;
  }
  cout << "end" << endl;
  /* 出力 */
  for (int i = 0; i < N; i++) {
    cout << mp[b[i]]-1 << endl;
  }

  return 0;
}
