#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int W, H, N, x, y, a;
  vector< pair<int, int> > p;
  vector<int> query;
  cin >> W >> H >> N;
  for (int i = 0; i < N; i++) {
    cin >> x >> y >> a;
    p.push_back(make_pair(x, y));
    query.push_back(a);
  }

  /* 計算 */
  int lx = 0, rx = W, dy = 0, uy = H;
  for (int i = 0; i < N; i++) {
    switch (query[i])
    {
    case 1:
      lx = max(lx, p[i].first);
      break;
    case 2:
      rx = min(rx, p[i].first);
      break;
    case 3:
      dy = max(dy, p[i].second);
      break;
    case 4:
      uy = min(uy, p[i].second);
      break;
    default:
      break;
    }
  }

  /* 出力 */
  if ( (rx - lx) > 0 && (uy - dy) )
  {
    int area = (rx - lx) * (uy - dy);
    cout << area << endl;
  }
  else
  {
    cout << 0 << endl;
  }

  return 0;
}
