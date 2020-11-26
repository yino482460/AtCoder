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

void dijkstra(int start, int N, Graph G[]){
  priority_queue<pair<int, int>> PQ;  // nodeID, distance
  vector<int> visit(N, WHITE);
  // 距離の初期化
  for (int i = 0; i < N; i++) {
    dist[i] = INF;
  }
  dist[start] = 0;
  PQ.push(make_pair(0, 0));
  visit[start] = GRAY;



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

  return 0;
}
