#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N, 0);
  int L, R, T;
  for (int i = 0; i < Q; i++) {
    cin >> L >> R >> T;
    L--; R--;
    for (int j = L; j <= R; j++) {
      a[j] = T;
    }
  }

  /* 出力 */
  for (int i = 0; i < N; i++) {
    cout << a[i] << endl;
  }

  return 0;
}
