#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int a, b, N;
  cin >> a>> b>> N;

  /* 計算 */
  int tmp = 0;
  if (a < b) {
    tmp = a;
    a = b;
    b = tmp;
  }
  /* ユークリッドの互除法 */
  int r = a%b;
  int lcm = a*b;  // 最小公倍数
  while (r != 0)
  {
    a = b;
    b = r;
    r = a%b;
  }
  lcm = lcm/b;
  /* 最小の数字を計算 */
  int x = N/lcm;
  if ( x*lcm < N )
  {
    cout << (x + 1) * lcm << endl;
  } else {
    cout << x * lcm << endl;
  }

  return 0;
}
