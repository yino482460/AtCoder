#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  string S,D;
  cin >> S;
  D = "WBWBWWBWBWBW";

  /* 計算 */
  int num = 0;
  while (1)
  {
    if (S.substr(0, D.size()) == D) {
      break;
    }
    num++;
    D += D[0];
    D = D.substr(1, D.size() - 1);
  }

  /* 出力 */
  switch (num)
  {
  case 0:
    cout << "Do" << endl;
    break;
  case 2:
    cout << "Re" << endl;
    break;
  case 4:
    cout << "Mi" << endl;
    break;
  case 5:
    cout << "Fa" << endl;
    break;
  case 7:
    cout << "So" << endl;
    break;
  case 9:
    cout << "La" << endl;
    break;
  case 11:
    cout << "Si" << endl;
    break;
  default:
    break;
  }

  return 0;
}
