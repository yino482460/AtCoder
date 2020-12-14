#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int W, H;
  cin >> W>> H;

  // 計算
  if ( 3*W == 4*H )
  {
    cout << "4:3" << endl;
  }
  else
  {
    cout << "16:9" << endl;
  }

  return 0;
}
