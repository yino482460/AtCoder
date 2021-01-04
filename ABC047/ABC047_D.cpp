#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, T, a;
  cin >> N >> T;
  vector<int> A;
  for (int i = 0; i < N; i++) {
    cin >> a;
    A.push_back(a);
  }

  /* 計算 */
  int minA = 1e9+100;
  vector<int> B;
  B.push_back(0);
  for (int i = 0; i < N; i++) {
    int X;
    minA = min(minA, A[i]);
    X = A[i]-minA;
    if (X > B[0]) {
      B.erase(B.begin(), B.end());
      B.push_back(X);
    } else if (X == B[0]) {
      B.push_back(X);
    }
  }

  /* 出力 */
  cout << B.size() << endl;

  return 0;
}
