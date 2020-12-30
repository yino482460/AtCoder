#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1e9+7;

#define MAX 1000005
long long mod[MAX];

void init() {
  mod[0] = 1;
  for (int i = 1; i <= MAX; i++)
  {
    mod[i] = (mod[i-1]*i)%MOD;
  }
}

// 逆元の計算本体
long long invMethod(long long a, long b, long long p) {
  if (b == 0)
  {
    return 1;
  }
  else if (b % 2 == 0) // 偶数
  {
    long long d = invMethod(a, b / 2, p);
    return (d * d) % p;
  }
  else // 奇数
  {
    return (a * invMethod(a, b - 1, p)) % p;
  }
}

long long modCombi(int n, int k) {
  long long mod_nCk;
  long long a = (mod[n - k] * mod[k]) % MOD;
  mod_nCk = (mod[n] * (invMethod(a, MOD - 2, MOD))) % MOD;
  return mod_nCk;
}

int main(int argc, char const *argv[])
{
  /* 入力 */
  int H, W, A, B;
  cin >> H >> W >> A >> B;

  /* 計算 */
  init();

  long long ans = 0;
  for (int i = 1; i <= H-A; i++) {
    int x, y;
    x = i+B-2; y = H+W-B-i-1;
    ans += modCombi(x, i-1)*modCombi(y, H-i)%MOD;
    ans %= MOD;
  }

  /* 出力 */
  cout << ans << endl;

  return 0;
}
