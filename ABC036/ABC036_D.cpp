#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll mod = 1e9+7;
static const int MAX = 100005;

ll f[MAX], g[MAX];
vector<vector<int> > G(MAX);

void init(){
  for (int i = 0; i < MAX; i++) {
    f[i] = 1;
    g[i] = 1;
  }
}

void treeDP(int v, int prev = -1) {
  ll sum_b = 1, sum_w = 1;  // 黒、白
  for (int i = 0; i < G[v].size(); i++) {
    int u = G[v][i];
    if (u == prev)
    {
      continue;
    }
    treeDP(u);
    sum_w *= f[u];
    sum_b *= g[u];
    sum_w %= mod;
    sum_b %= mod;
  }
  g[v] = sum_w;
  f[v] = (g[v] + sum_b)%mod;
}

int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, a, b;
  cin >> N;
  for (int i = 0; i < N-1; i++) {
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  /* 計算 */
  // treeDP
  init();
  treeDP(0);

  /* 出力 */
  ll ans = (f[0] + g[0])%mod;
  cout << ans << endl;

  return 0;
}
