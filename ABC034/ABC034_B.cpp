#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int n;
  cin >> n;

  /* 計算 */
  if ( n%2 == 0 )
  {
    cout << n-1 << endl;
  }
  else
  {
    cout << n+1 << endl;
  }

  return 0;
}
