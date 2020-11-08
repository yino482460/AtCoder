#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  unsigned long NumLen, Lim, tmp;
  cin >> NumLen >> Lim;
  vector<unsigned long> s;
  for (long i = 0; i < NumLen; i++)
  {
    cin>> tmp;
    s.push_back(tmp);
    if (tmp == 0) // 数列に0があるかどうか
    {
      cout << NumLen << endl;
      return 0; // 終了
    }
  }


  /* メイン計算 尺取法 */
  long left = 0, right = 0; // 左端と右端
  long product = 1; // 数列の積
  long ans = 0; // 答え

  while (left < NumLen)
  {
    while ( right < NumLen && (product * s[right] <= Lim) )
    {
      product *= s[right];
      right++;
    }
    ans = max(ans, right - left);
    // 同じ位置の場合は右端をずらす
    if (left == right)
    {
      right++;
    } else {
      product /= s[left];
    }
    left ++;
  }

  /* 出力 */
  cout << ans << endl;
  return 0;
}
