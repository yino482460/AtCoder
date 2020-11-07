#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N;
  cin >> N;
  vector<int> a(N);
  for (size_t i = 0; i < N; i++)
  {
    cin >> a[i];
  }

  /* メイン計算 */
  vector<int> dp(N);   // 累積和の計算
  dp[0] = a[0];
  dp[1] = a[1];
  for (size_t i = 2; i < N; i++)
  {
    dp[i] = dp[i-2] + a[i];
  }

  // 全探索
  int Takahashi = INT16_MIN;      // 高橋の得点
  int Aoki = INT16_MIN;           // 青木の得点
  int ans = INT16_MIN;            // 得点
  for (int i = 0; i < N; i++)  // 高橋の選択位置
  {
    int Aoki_max = INT16_MIN; // 青木の最高得点
    int Aoki_max_j = 0; // Takahashiの得点が最大になる位置
    for (int j = 0; j < N; j++)  // 青木の選択位置
    {
      if (i==j)
      {
        continue;
      }
      int left = min(i,j), right = max(i, j); // 配列Tの両端を設定
      // 青木の得点の計算
      if ((right - left)%2 == 0)
      {
        if ((left -1) >= 0) {
          Aoki = dp[right-1] - dp[left-1];
        } else {
          Aoki = dp[right-1];
        }
      }
      else
      {
        if ((left - 1) >= 0)
        {
          Aoki = dp[right] - dp[left-1];
        }
        else
        {
          Aoki = dp[right];
        }
      }
      // 青木の最高得点を更新
      if (Aoki > Aoki_max)
      {
        Aoki_max = Aoki;
        Aoki_max_j = j;
      }
    }

    int left = min(i, Aoki_max_j), right = max(i, Aoki_max_j); // 配列Tの両端を設定
    // 高橋の得点の計算
    if ((right - left) % 2 == 0)
    {
      if ((left - 2) >= 0)
      {
        Takahashi = dp[right] - dp[left - 2];
      }
      else
      {
        Takahashi = dp[right];
      }
    }
    else
    {
      if ((left - 2) >= 0)
      {
        Takahashi = dp[right - 1] - dp[left - 2];
      }
      else
      {
        Takahashi = dp[right - 1];
      }
    }
    ans = max(ans, Takahashi);
  }

  /* 出力 */
  cout << ans <<endl;
  return 0;
}
