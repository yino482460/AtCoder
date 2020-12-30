#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int a[3];
  set<int> A;
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
    A.insert(a[i]);
  }

  /* 出力 */
  cout << A.size() << endl;


  return 0;
}
