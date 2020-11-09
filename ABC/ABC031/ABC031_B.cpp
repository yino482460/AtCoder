#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int Low, High, Week;
  cin >> Low>> High;
  cin >> Week;

  int time[Week];
  for (size_t i = 0; i < Week; i++)
  {
    cin >> time[i];
  }

  /* 判定 */
  for (size_t i = 0; i < Week; i++)
  {
    if (time[i] < Low)
    {
      cout << Low - time[i] << endl;
    }
    else if (time[i] > High)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << 0 << endl;
    }
  }
  return 0;
}
