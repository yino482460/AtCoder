#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BIT
{
  private:
    vector<T> tree;
    int size;
    T init;

  public:
    BIT(int size_num){
      size = size_num;
      tree.assign(size + 1, 0);
    }

    void update(int i, T w)
    {
      for (int x = i; x <= size; x += x & -x)
      {
        tree[x] = max(tree[x], w);
      }
    }

    T query(int i)
    {
      T ret = 0;
      for (int x = i; x > 0; x -= x & -x)
      {
        ret = max(ret, tree[x]);
      }
      return ret;
    }
};

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
  if (a.first != b.first)
  {
    return a.first < b.first;
  }
  else
  {
    return a.second > b.second;
  }
}

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N;
  cin >> N;
  vector<pair<int, int> > size(N);
  for (int i = 0; i < N; i++) {
    cin >> size[i].first >> size[i].second;
  }

  /* 計算 */
  sort(size.begin(), size.end(), comp);
  vector<int> dp(N, 0);
  BIT<int> bit(100000);
  for (int i = 0; i < N; i++) {
    dp[i] = bit.query(size[i].second-1) + 1;
    bit.update(size[i].second, dp[i]);
  }

  /* 出力　*/
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;

  return 0;
}
