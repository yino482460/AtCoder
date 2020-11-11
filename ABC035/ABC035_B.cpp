#include <bits/stdc++.h>
using namespace std;

struct Point
{
  int x;
  int y;
  void init(int v) {
    x = v;
    y = v;
  }
};

// 最大値の計算
int calMax (Point p, int unkown) {
  int distanceMax = abs(p.x) + abs(p.y) + distanceMax;
  return distanceMax;
}

// 最小値の計算
int calMin (string s, Point p, int unkown) {
  int distance = abs(p.x) + abs(p.y);
  int distanceMin;
  if ( distance > s.size() )
  {
    if ((distance - s.size())%2 == 0)
    {
      distanceMin = 0;
    }
    else
    {
      distanceMin = 1;
    }
  }
  else
  {
    distanceMin = s.size() - distance;
  }
  return distanceMin;
}


int main(int argc, char const *argv[])
{
  /* 入力 */
  string S;
  int T;
  cin >> S>> T;

  /* 計算 */
  int unkown = 0; // ?の個数
  Point p;
  p.init(0);
  // 座標の計算
  for (int i = 0; i < S.size(); i++) {
    cout << "str: " << S[i] << endl;
    switch (S[i])
    {
    case 'L':
      cout << "L" << endl;
      p.x--;
      break;
    case 'R':
      cout << "R" << endl;
      p.x++;
      break;
    case 'U':
      cout << "U" << endl;
      p.y++;
      break;
    case 'D':
      cout << "D" << endl;
      p.y--;
      break;
    default:
      cout << "?" << endl;
      unkown++; // 読み取り不明
      break;
    }
  }

  /* 出力 */
  int ans;
  if (T == 1)
  {
    ans = calMax(p, unkown);
  }
  else
  {
    ans = calMin(S, p, unkown);
  }
  cout << ans << endl;

  return 0;
}
