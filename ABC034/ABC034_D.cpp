#include <bits/stdc++.h>
using namespace std;

// 食塩水
struct saline
{
  int w;  // 食塩水重量
  int p;  // 濃度
};


int main(int argc, char const *argv[])
{
  /* 入力 */
  long N, K; // 総数N個、抽出K個
  vector<saline> saline;
  cin >> N>> K;
  saline.reserve(N);
  for (int i = 0; i < N; i++)
  {
    cin >> saline[i].w>> saline[i].p;
  }

  /* 計算 */
  /* 方針：二分検索 */
  double OK = 0;
  double NG = 100;

  return 0;
}
