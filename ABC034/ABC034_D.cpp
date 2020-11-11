#include <bits/stdc++.h>
using namespace std;

// 食塩水
struct saline
{
  double w;  // 食塩水重量
  double p;  // 濃度
};

int main(int argc, char const *argv[])
{
  /* 入力 */
  long N, K; // 総数N個、抽出K個
  vector<saline> saline;  // 食塩水
  cin >> N>> K;
  saline.reserve(N);
  for (int i = 0; i < N; i++)
  {
    cin >> saline[i].w>> saline[i].p;
  }

  /* 計算 */
  /* 方針：二分検索 */
  double OK = 0;  // 濃度
  double NG = 100;
  double target; // 目標濃度
  /* 二分検索 */
  for (size_t i = 0; i < 100; i++)
  {
    // 目標濃度からのズレを計算し判定
    target = (OK + NG) * 0.5; // 目標濃度
    double isMake = 0;  // 食塩水が作成できるか
    vector<double> v(N);
    for (long i = 0; i < N; i++) // 目標濃度からのズレを計算
    {
      v[i] = saline[i].w * (saline[i].p - target);
    }
    // 降順にソート
    sort(v.rbegin(), v.rend());
    // 作成できるかの計算：0以上であれば良い
    for (long i = 0; i < K; i++)
    {
      isMake += v[i];
    }
    // 目標値の更新
    if ( isMake >= 0 )
    {
      OK = target;
    }
    else
    {
      NG = target;
    }
    // cout << "target: "<< target << endl;
  }

  /* 出力 */
  cout << fixed << setprecision(15) << target << endl;

  return 0;
}
