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
  }


  /* メイン計算 尺取法 */
  long left, right; // 左端と右端
  long product; // 数列の積
  long ans = 0; // 答え
  for (long i = 0; i < NumLen; i++)
  {
    long len;
    left = i;
    right = i;
    product = s[left];
    // cout << "s[right] = " << s[right] << endl;
    // cout << "right: " << right << endl;
    // cout << "product: " << product << endl;

    while (product <= Lim)
    {
      if (right > NumLen) { break; }  // 文字数を超えたら終了
      right++;  // 右端を伸ばす
      product *= s[right];
      cout << "product: " << product << endl;
    }

    len = right - left; // 数列の長さ
    ans = max(ans, len);
  }

  /* 出力 */
  cout<< ans <<endl;
  return 0;
}
