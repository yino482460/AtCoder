#include <bits/stdc++.h>
using namespace std;

struct Point
{
  int x;
  int y;
};


int main(int argc, char const *argv[])
{
  /* 入力 */
  string S;
  int T;
  cin >> S>> T;

  /* 計算 */
  int unkown = 0; // ?の個数
  Point p;
  // 座標の計算
  for (int i = 0; i < S.size(); i++) {
    switch (S[i])
    {
    case 'L':
      p.x--;
      break;
    case 'R':
      p.x++;
      break;
    case 'U':
      p.y++;
      break;
    case 'D':
      p.y--;
      break;
    default:
      unkown++;
      break;
    }
  }


  return 0;
}
