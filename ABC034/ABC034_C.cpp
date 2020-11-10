#include <bits/stdc++.h>
using namespace std;

const long p = 1e9+7;
// 階乗
long facrialMethod (long k);
// 逆元の計算
long invMethod (long a, long b, long p);

int main(int argc, char const *argv[])
{
  /* 入力 */
  long W, H;
  cin >> W>> H;

  /* 計算 */
  // (W+H-2)C(H-1) = (H+W-2)!/(W-1)!*(H-1)! の計算が目標
  /* 方針：階乗同士は各数字の余りの積、割り算は逆元にして掛けて割る */
  // ステップ 1：分子の計算
  long numerator = 1; // 分子：(H+W-2)!
  vector<long> modp;
  modp.push_back(1);  //modp[0] = 1;
  for (int i = 1; i <= H+W-2; i++)
  {
    numerator = (numerator * i) % p;
    modp.push_back(numerator);
  }
  // ステップ 2：逆元の計算
  long a = (modp[W-1]*modp[H-1])%p;
  long invModp = invMethod(a, p-2, p);
  // ステップ 3：逆元を掛けて、組み合わせの余りを計算
  long ans = (numerator * invModp) % p;

  /* 出力 */
  cout << ans << endl;

  return 0;
}

// 階乗本体
long facctorialMethod(long k) {
  long ans = 1;
  for (int i = 0; i <= k; i++)
  {
    ans *= i;
  }
  return ans;
}

// 逆元の計算本体
long invMethod(long a, long b, long p) {
  if (b == 0)
  {
    return 1;
  }
  else if (b%2 == 0)  // 偶数
  {
    long d = invMethod(a, b/2, p);
    return (d*d)%p;
  }
  else                // 奇数
  {
    return ( a*invMethod(a, b-1, p) )%p;
  }
}
