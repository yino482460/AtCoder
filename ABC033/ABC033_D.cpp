#include <bits/stdc++.h>
using namespace std;
struct Point
{
  int x, y;
};


int main(int argc, char const *argv[])
{
  /* 入力 */
  long long N;  // 点の数
  vector<Point> p;  // 頂点の座標

  cin>> N;
  p.resize(N);
  for (size_t i = 0; i < N; i++)
  {
    cin>> p[i].x>>p[i].y;
  }

  /* 計算 */
  double eps = 1e-15;   // 誤差
  long long sum = N*(N-1)*(N-2)/6;
  long long ans[3] = {0};     // 各三角形の個数
  for (int i = 0; i < N; i++)
  {
    vector<double> rad; // 角度
    for (int j = 0; j < N; j++)
    {
      if (i != j)
      {
        rad.push_back(atan2(p[j].y - p[i].y, p[j].x - p[i].x));
      }
    }
    // 角度の大きさ順にソート
    sort(rad.begin(), rad.end());
    // 角度を追加計算
    for (int j = 0; j < N-1; j++)
    {
      rad.push_back(rad[j]+2*M_PI);
    }
    // 三角形の分類
    for (int j = 0; j < N - 1; j++)
    {
      // 直角三角形
      ans[1] += upper_bound(rad.begin(), rad.end(), rad[j] + M_PI / 2 + eps) - lower_bound(rad.begin(), rad.end(), rad[j] + M_PI / 2 - eps);
      // 鈍角三角形
      ans[2] += lower_bound(rad.begin(), rad.end(), rad[j] + M_PI) - upper_bound(rad.begin(), rad.end(), rad[j] + M_PI / 2 + eps);
    }
  }

  /* 出力 */
  // 鋭角三角形
  ans[0] = sum - ans[1] - ans[2];
  cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;

  return 0;
}
