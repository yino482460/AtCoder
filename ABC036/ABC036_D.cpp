#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll mod = 10e9+7;
static const int NIL = -1;  // 根
static const int MAX = 100005;

ll f[MAX], g[MAX];

struct Node {
  int parent = NIL;
  vector<int> child;
};

void treeDP(int v, Node node[]) {
  ll sum_b = 1, sum_w = 1;  // 黒、白
  int count = node[v].child.size();
  for (int i = 0; i < count; i++) {
    int u = node[v].child[i];
    treeDP(u, node);
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
  Node node[N-1];
  for (int i = 0; i < N-1; i++) {
    cin >> a >> b;
    a--; b--;
    node[a].child.push_back(b);
    node[b].parent = a;
  }

  /* 計算 */
  int root;
  for (int i = 0; i < N-1; i++) {
    if (node[i].parent == NIL)
    {
      root = i;
      break;
    }
  }
  // treeDP
  treeDP(root, node);

  /* 出力 */
  ll ans = (f[root] + g[root])%mod;
  cout << ans << endl;

  return 0;
}
