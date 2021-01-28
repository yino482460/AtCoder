#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int H, W;
  cin >> H >> W;
  char C[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> C[i][j];
    }
  }

  /* 出力 */
  for (int i = -1; i < 2*H-1; i++) {
    for (int j = 0; j < W; j++) {
      cout << C[(i+1)/2][j];
    }
    cout << endl;
  }

  return 0;
}
