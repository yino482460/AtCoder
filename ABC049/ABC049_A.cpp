#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  char cha;
  cin >> cha;

  /* 出力 */
  if (cha == 'a' || cha == 'e' || cha == 'i' || cha == 'o' || cha == 'u')
  {
    cout << "vowel" << endl;
  }
  else
  {
    cout << "consonant" << endl;
  }

  return 0;
}
