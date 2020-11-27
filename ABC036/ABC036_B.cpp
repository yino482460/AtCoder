#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N;
  cin >> N;
  char S[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> S[i][j];
    }
  }

  /* 出力 */
  for (int j = 0; j < N; j++) {
    for (int i = N-1; i >= 0; i--) {
      cout << S[i][j];
    }
    cout << endl;
  }
  return 0;
}
