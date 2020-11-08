#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N;
  cin>> N;

  /* 計算 */
  set<int> n;
  for (size_t i = 0; i < 4; i++)
  {
    int x = N%10;  // 桁ごとに分解
    n.insert(x);  // ユニークであれば追加
    N = N/10;
  }

  /* 判定 */
  if (n.size() == 1)  // 全て同じ
  {
    cout << "SAME" <<endl;
  }
  else
  {
    cout << "DIFFERENT" << endl;
  }

  return 0;
}
