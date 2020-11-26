#include <bits/stdc++.h>
using namespace std;

static const int MAX = 200000;
static const int INF = 1<<21;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

struct Edge
{
  int toNode;
  long long cost;
  Edge(int toNode, long long cost) : toNode(toNode), cost(cost) {}
};

using Graph = vector<vector<Edge>>;
vector<int> dist(MAX); // 始点からの最短経路を保持

void dijkstra(int start, int N, Graph G){
  priority_queue<pair<int, int>> PQ;  // weight, nodeID
  vector<int> visit(N, WHITE);
  // 距離の初期化
  for (int i = 0; i < N; i++) {
    dist[i] = INF;
  }
  dist[start] = 0;
  PQ.push(make_pair(dist[start], start));
  visit[start] = GRAY;

  while (!PQ.empty())
  {
    pair<int, int> node = PQ.top();
    PQ.pop();
    int id = node.second;
    visit[id] = BLACK;
    // 最小値を取り出し、それが最短でなければ無視
    if (dist[id] < node.first*(-1))
    {
      continue;
    }

    for (int j = 0; j < G[id].size(); j++) {
      int v = G[id][j].toNode;
      if (visit[v] == BLACK)
      {
        continue;
      }
      if (dist[v] > dist[id]+G[id][j].cost)
      {
        dist[v] = dist[id] + G[id][j].cost;   // 距離の更新
        PQ.push(make_pair(dist[v]*(-1), v));  // 最小値でヒープ
        visit[v] = GRAY;
      }
    }
  }
}



int main(int argc, char const *argv[])
{
  /* 入力 */
  int N, M, T;
  cin >> N >> M >> T;
  int A[N];
  Graph G1(N), G2(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int a, b, c;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    a--; b--;
    G1[a].push_back(Edge(b, c));
    G2[b].push_back(Edge(a, c));
  }

  /* 計算 */

  return 0;
}
