#include <bits/stdc++.h>
using namespace std;

struct Operation
{
  int left;
  int right;
};


int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, Q;
  vector<Operation> ope;
  cin >> N>> Q;
  int left, right;
  for (int i = 0; i < Q; i++) {
    cin >> left >> right;
    ope.push_back( {left, right} );
  }

  return 0;
}
