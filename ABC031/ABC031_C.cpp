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

  /* 最大値の計算 */
  int max = INT16_MAX;
  int T_score = 0;  // 高橋の得点
  int A_score = 0;  // 青木の得点
  vector<int> T;
  for (size_t i = 0; i < N; i++)  // 高橋の選択
  {
    for (size_t j = N-1; j > i; j--)  // 青木の選択
    {
      T.push_back(a[i]);
    }
  }

  for (size_t i = 0; i < T.size(); i++)
  {
    cout << T[i] << endl;
  }

  /* 出力 */
  // cout << max <<endl;
  return 0;
}
