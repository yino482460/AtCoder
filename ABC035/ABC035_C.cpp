#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, Q;
  vector<int> ope;
  cin >> N>> Q;
  ope.reserve(N);
  //cout << ope[3] << endl;
  int left, right;
  for (int i = 0; i < Q; i++) {
    cin >> left >> right;
    ope[left-1] += 1;
    if (right-1 < N-1)
    {
      ope[right] -= 1;
    }
  }
  cout << " ope[N]: " << ope[N];
  cout << endl;

  /* 計算 */
  char S[N];  // 操作後の文字列
  // imos法
  for (int i = 0; i < N-1; i++) {
    ope[i+1] += ope[i];
    cout << " ope[i]: " << ope[i];
    // 0:黒, 1:白
    if (ope[i]%2 == 0 )
    {
      S[i] = '0';
    }
    else
    {
      S[i] = '1';
    }
  }
  cout << endl;

  /* 出力 */
  cout << S << endl;

  return 0;
}
