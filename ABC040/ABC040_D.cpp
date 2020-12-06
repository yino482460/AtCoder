#include <bits/stdc++.h>
using namespace std;

int N, M, Q;

struct UnionFind {
  vector<int> parent, rank, sz; // par[i]:iの親の番号, rank[i]:ノードiのきの高さ, sz[i]:木のノードの数

  UnionFind(int N) {
    parent.resize(N);
    rank.resize(N,0);
    sz.resize(N,1);
    for (int i = 0; i < N; i++) {
      parent[i] = i;
    }
  }

  int root(int x) // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
  {
    if (parent[x] == x)
    {
      return x;
    }
    return parent[x] = root(parent[x]);
  }

  void unite(int x, int y) {
    link(root(x), root(y));
  }

  void link(int x, int y) {
    if (rank[x] > rank[y])
    {
      parent[y] = x;
      sz[x] += sz[y];
    } else
    {
      parent[x] = y;
      sz[y] += sz[x];
      if (rank[x] == rank[y])
      {
        rank[y]++;
      }
    }
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  int size(int x)
  { // 素集合のサイズ
    return sz[root(x)];
  }

  void init(int N)
  { //再初期化
    parent.resize(N);
    rank.assign(N, 0);
    sz.assign(N,1);
    for (int i = 0; i < N; ++i)
      parent[i] = i;
  }
};


int main(int argc, char const *argv[])
{
  /* 入力 */
  cin >> N >> M;
  vector<int> A(M), B(M);
  vector<pair<int, int> > Y(M);
  for (int i = 0; i < M; i++) {
    int y;
    cin >> A[i] >> B[i] >> y;
    A[i]--; B[i]--;
    Y[i] = {y, i};
  }
  sort(Y.begin(), Y.end());
  reverse(Y.begin(), Y.end());

  cin >> Q;
  vector<int> V(Q), ans(Q);
  vector<pair<int, int> > W(Q);
  for (int i = 0; i < Q; i++) {
    int w;
    cin >> V[i] >> w;
    V[i]--;
    W[i] = {w, i};
  }
  sort(W.begin(), W.end());
  reverse(W.begin(), W.end());

  /* 計算 */
  vector<pair<int, int> > X;
  for (int i = 0; i < M; i++)
  {
    X.emplace_back(make_pair(Y[i], i));
  }
  for (int i = 0; i < Q; i++)
  {
    X.emplace_back(make_pair(W[i], i + M));
  }
  sort(X.begin(), X.end());

  UnionFind uf(N);
  vector<int> res(Q,0);
  int j = 0;
  for (int i = 0; i < Q; i++) {
    while (j < M && Y[j].first > W[i].first)
    {
      auto p = Y[j].second;
      uf.unite(A[p], B[p]);
      j++;
    }
    auto k = W[i].second;
    ans[k] = uf.size(V[k]);
  }

  /* 出力 */
  for (int i = 0; i < Q; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
