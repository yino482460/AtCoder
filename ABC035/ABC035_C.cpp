#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, Q;
  vector<int> ope;
  cin >> N>> Q;
  ope.reserve(N);
  int left, right;
  for (int i = 0; i < Q; i++) {
    cin >> left >> right;
    ope[left-1] += 1;
    ope[right] -= 1;
  }

  /* 計算 */
  // imos法
  for (int i = 0; i < N; i++) {
    if (i < N-1)
    {
      ope[i + 1] += ope[i];
    }
    // 0:黒, 1:白
    if (ope[i]%2 == 0 )
    {
      cout << 0;
    }
    else
    {
      cout << 1;
    }
  }

  /* 出力 */
  cout << endl;

  return 0;
}
