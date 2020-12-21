#include <bits/stdc++.h>
using namespace std;
int main()
{
  string a, b, c;
  cin >> a >> b >> c;
  char x;
  int a1 = 0, b1 = 0, c1 = 0, aa, bb, cc;
  aa = a.size() + 1;
  bb = b.size() + 1;
  cc = c.size() + 1;
  x = 'a';
  while (a1 != aa && b1 != bb && c1 != cc)
  {
    if (x == 'a')
    {
      x = a[a1];
      a1++;
      continue;
    }
    if (x == 'b')
    {
      x = b[b1];
      b1++;
      continue;
    }
    if (x == 'c')
    {
      x = c[c1];
      c1++;
      continue;
    }
  }
  if (a1 == aa)
  {
    cout << "A" << endl;
    return 0;
  }
  if (b1 == bb)
  {
    cout << "B" << endl;
    return 0;
  }
  if (c1 == cc)
  {
    cout << "C" << endl;
    return 0;
  }
}
