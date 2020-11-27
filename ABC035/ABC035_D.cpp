#include <bits/stdc++.h>
using namespace std;

static const int MAX = 100005;
static const int INF = 1<<21;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

struct Edge
{
  long long toNode;
  long long cost;
  Edge(long long toNode, long long cost) : toNode(toNode), cost(cost) {}
};

using Graph = vector<vector<Edge> >;
vector<long long> dist(MAX); // 始点からの最短経路を保持

void dijkstra(int start, int N, Graph G){
  priority_queue<pair<long long, long long> > PQ;  // weight, nodeID
  int visit[N];
  // 距離の初期化
  for (int i = 0; i < N; i++) {
    dist[i] = INF;
    visit[i] = WHITE;
  }
  dist[start] = 0;
  PQ.push(make_pair(dist[start], start));
  visit[start] = GRAY;

  while (!PQ.empty())
  {
    pair<long long, long long> node = PQ.top();
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
  long long A[N];
  Graph G1(N), G2(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  long long a, b, c;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    a--; b--;
    G1[a].push_back(Edge(b, c));
    G2[b].push_back(Edge(a, c));
  }

  /* 計算 */
  dijkstra(0, N, G1);
  long long dist1[N]; // 始点0からの最短距離
  for (int i = 0; i < N; i++) {
    dist1[i] = dist[i];
  }
  long long income = 0;
  dijkstra(0, N, G2);
  for (int i = 0; i < N; i++) {
    income = max( income, (long long)(T-dist1[i]-dist[i])*A[i] );
  }

  /* 出力 */
  cout << income << endl;

  return 0;
}
