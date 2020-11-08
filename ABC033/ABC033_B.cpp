#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N;
  vector<string> S;

  cin >>N;
  S.resize(N);

  /* 計算 */
  double sum = 0, plt, sum_plt = 0, max_plt = 0, no;
  for (size_t i = 0; i < N; i++)
  {
    cin >> S[i]>> plt;
    sum_plt += plt;

    if (max_plt < plt)
    {
      max_plt = max(max_plt, plt);
      no = i;
    }
  }

  /* 出力 */
  if (max_plt/sum_plt > 0.5)
  {
    cout << S[no] <<endl;
  }
  else
  {
    cout << "atcoder" <<endl;
  }

  return 0;
}
