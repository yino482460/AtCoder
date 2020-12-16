#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, K; cin >> N >> K;
  vector<int> D(10, 0);
  for (int i = 0; i < K; i++) {
    int d;
    cin >> d;
    D[d]++;
  }

  /* 出力 */
  int ans = N;
  while (1)
  {
    int tmp = ans;
    bool flag = true;
    while (tmp > 0)
    {
      if (D[tmp%10] != 0)
      {
        flag = false;
        break;
      }
      tmp /= 10;
    }

    if (flag)
    {
      cout << ans << endl;
      break;
    }
    ans++;
  }

  return 0;
}
