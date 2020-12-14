#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int H[2], W[2];
  for (int i = 0; i < 2; i++) {
    cin >> H[i] >> W[i];
  }

  /* 判定 */
  if (H[0] == H[1] || H[0] == W[1] || W[0] == H[1] || W[0] == W[1])
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }

  return 0;
}
